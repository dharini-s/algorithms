import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Graph
{
	private List<Vertex> vertices;
	private List<Edge> edges;
	
	public Graph(List<Vertex> v, List<Edge> e)
	{
		this.vertices = v;
		this.edges = e;
	}
	
	public List<Vertex> getVertices()
	{
		return vertices;
	}

	public void setVertices(List<Vertex> vertices)
	{
		this.vertices = vertices;
	}

	public List<Edge> getEdges()
	{
		return edges;
	}

	public void setEdges(List<Edge> edges)
	{
		this.edges = edges;
	}
	
	public void bfs(Vertex v)
	{
		Queue<Vertex> queue = new LinkedList<Vertex>();
		
		//All vertices are already marked unvisited
		v.setState(State.VISITING);
		queue.add(v);
		Vertex vertex;
		
		while(queue!= null && !queue.isEmpty())
		{
			vertex = queue.remove();
			System.out.println(vertex.toString());
			for(int i=0; i< vertex.getAdjList().size(); i++)
			{
				//System.out.println("AdjList size: " + i +" "+ vertex.getAdjList().size());
				Vertex neighbour = vertex.getAdjList().get(i);
				if(neighbour.getState().equals(State.UNVISITED))
				{
					neighbour.setState(State.VISITING);
					queue.add(neighbour);
				}
			}
			
			vertex.setState(State.VISITED);
			vertex.toString();
		}
	}
	
	public List<Vertex> unconnected(Vertex v, List<Vertex> all)
	{
		Queue<Vertex> queue = new LinkedList<Vertex>();
		List<Vertex> unconnNodes = new LinkedList<Vertex>();
		List<Vertex> connNodes = new LinkedList<Vertex>();
		
		//Set all to unvisited just in case. Totally forgot this
		for(int i=0; i < getVertices().size(); i++)
		{
			getVertices().get(i).setState(State.UNVISITED);
		}
		v.setState(State.VISITING);
		queue.add(v);
		Vertex vertex;
		
		while(queue != null && !queue.isEmpty())
		{
			vertex = queue.remove();
			
			if(!connNodes.contains(vertex))
				connNodes.add(vertex);
			for(int i=0; i < vertex.getAdjList().size(); i++)
			{
				//System.out.println("AdjList size: " + i +" "+ vertex.getAdjList().size());
				Vertex neighbour = vertex.getAdjList().get(i);
				if(neighbour.getState().equals(State.UNVISITED))
				{
					neighbour.setState(State.VISITING);
					queue.add(neighbour);
				}
			}
			vertex.setState(State.VISITED);
		}
		
		System.out.println("No. of unconnected nodes: " + (all.size() - connNodes.size()));
		return unconnNodes;
	}
	

	public static void main(String args[])
	{
		//Not using adjList of vertex for now
		List<Vertex> v = new LinkedList<Vertex>();
		Vertex v1 = new Vertex(1);
		Vertex v2 = new Vertex(2);
		Vertex v3 = new Vertex(3);
 		Vertex v4 = new Vertex(4);
		
 		//Setting adjList for each vertex
 		List<Vertex> adjList = new LinkedList<Vertex>();
		adjList.add(v2);
		adjList.add(v3);
		v1.setAdjList(adjList);
		
		adjList = new LinkedList<Vertex>();
		adjList.add(v4);
		v2.setAdjList(adjList);
		
		adjList = new LinkedList<Vertex>();
		adjList.add(v2);
		v3.setAdjList(adjList);
		
		adjList = new LinkedList<Vertex>();
		adjList.add(v3);
		v4.setAdjList(adjList);
		
		v.add(v1);
		v.add(v2);
 		v.add(v3);
		v.add(v4);

		Edge e1 = new Edge(1, 2);
		List<Edge> e = new LinkedList<Edge>();
		e.add(e1);
		e1 = new Edge(1, 3);
		e.add(e1);
		e1 = new Edge(2, 4);
		e.add(e1);
		e1 = new Edge(4, 3);
		e.add(e1);
		e1 = new Edge(3, 2);
		e.add(e1);
		
		
		Graph g = new Graph(v, e);
		g.bfs(v4);
		
		//v has all vertices
		g.unconnected(v2, v);
	}
}
