import java.util.*;

enum Answers 
{
	BAD_MARKED, 
	BAD_UNMARKED, 
	OK_MARKED, 
	OK_UNMARKED
}
		
class Question
{
		private List<Answers> listOfAnswers = new ArrayList<Answers>();
		public Question(Answers[] answers) 
		{ 
			for(Answers answer : answers)
			{
				listOfAnswers.add(answer);
			}
		}
		
		public int whatType(Answers answer)
		{
			int howMany = 0;
			for(Answers ans : listOfAnswers)
			{
				if(ans == answer) howMany++;
			}
			return howMany;
		}
		
		public Answers whichTypeOfAnswer(int ID)
		{
			return listOfAnswers.get(ID);
		}
}

class Oceniacz
{
		private int points;
		public Oceniacz() { points = 0; }
		public void Ocen(Question question);
		public int getPoints() { return points; }
		public void setPoints(int points) { this.points = points; }
}

class OceniaczPojedynczyWybor extends Oceniacz
{
	public void Ocen(Question question)
	{
		if(question.whatType(Answer.OK_MARKED) == 1) setPoints(1);
	}
}

class OceniaczWielokrotnyWybor extends Oceniacz
{
	public void Ocen(Question question)
	{
		if(question.whatType(Answer.BAD_MARKED) > 0) setPoints(-1);
		else if(question.whatType(Answer.OK_MARKED) == 0 
			&& question.whatType(Answer.BAD_MARKED) == 0) setPoints(0);
		else if 
	}
}

public class pytanie
{
	public static void main(String[] args)
	{
		System.out.println("test");
	}
}
