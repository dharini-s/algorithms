import java.util.LinkedList;
import java.util.List;


public class Vertex
{
	private int id;
	private State state;
	List<Vertex> adjList;
	 
	//Constructor with only value specified
	public Vertex(int value)
	{
		//Apparently, you can do this; looks neater
		this(value, null);
	}
	
	//Overloaded constructor
	public Vertex(int value, List<Vertex> list)
	{
		this.id = value;
		this.state = State.UNVISITED;
		this.adjList = list;
		
	}
		
	public int getId()
	{
		return id;
	}

	public void setId(int id)
	{
		this.id = id;
	}

	public State getState()
	{
		return state;
	}

	public void setState(State state)
	{
		this.state = state;
	}

	public List<Vertex> getAdjList()
	{
		return adjList;
	}

	public void setAdjList(List<Vertex> adjList)
	{
		this.adjList = adjList;
	}


	@Override
	public String toString()
	{
		return "Vertex [id=" + id + "]";
	}
	
	public static void main(String args[]) //look up argc and argv
	{
		//To do
	}
}

