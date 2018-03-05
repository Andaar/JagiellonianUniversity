import java.io.*;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import javax.swing.JFileChooser;
class Run
{
    public static void main(String[] args)
    {
        WybieraniePlikow wybieranie = new WybieraniePlikow();
        wybieranie.Test();
    }	
}

class WybieraniePlikow
{
		public static void Test()
		{
			JFileChooser fc = new JFileChooser(FileSystemView.
				getFileSystemView().getParentDirectory(new File("email.java")));
			int returnVal = fc.showOpenDialog(null);
			System.out.println(returnVal);
			byte test;
			if(returnVal == JFileChooser.APPROVE_OPTION)
			{
				File file = fc.getSelectedFile();
				test = (byte)file.length();
				JOptionPane.showMessageDialog(null, "Wybrany plik to " + 
					file.getName() + " " + Byte.toString(test));
				Attachment at = new Attachment(file.getName(), (byte)file.length());
				
				JOptionPane.showMessageDialog(null, "Wybrany plik to " + 
					at.toString());
			}
		}
}

class Email
{
	private String message;
	private Format formatTekstu;
	
	private enum Format
	{
		PLAIN("Plain text"),
		HTML("HTML file");
		
		private String text;
		
		private Format(String text)
		{
			this.text = text;
		}
		
		public String toString()
		{
			return this.text;
		}
	}
	
	Email()
	{
		message = "";
	}
	
	Email(String message, Format format)
	{
		this.message = message;
		this.formatTekstu = format;
	}
	
	public String getWiadomosc()
	{
		return message;
	}
	
	public String getFormat()
	{
		return this.formatTekstu.toString();
	}
	
	public void setWiadomosc(String message)
	{
		this.message = message;
	}
	
	public void setFormat(Format formatTekstu)
	{
		this.formatTekstu = formatTekstu;
	}
	
	public String toString()
	{
		switch(this.formatTekstu)
		{
			case PLAIN:
				return message;
			case HTML:
				return "<html><body><b>"+message+"</b></body></html>";
			default:
				return "Niepoprawny tryb enum.";
		}
	}	
}

class Attachment
{
	private String fileName;
	private byte size;
	
	Attachment(String fileName, byte size)
	{
		this.fileName = fileName;
		this.size = size;
	}
	
	public String getFileName()
	{
		return this.fileName;
	}
	
	public byte getSize()
	{
		return size;
	}
	
	public String toString()
	{
		return this.fileName+" "+Byte.toString(this.size);
	}
}
