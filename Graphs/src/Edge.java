
public class Edge
{
	private int src;
	private int dest;
	private int weight;
	
	public Edge(int from, int to)
	{
		this.src = from;
		this.dest = to;
		weight = 1; //I'm setting default weight for unweighted graph as 1
	}
	
	public Edge(int from, int to, int weight)
	{
		this.src = from;
		this.dest = to;
		this.weight = weight;
	}

	public int getSrc()
	{
		return src;
	}

	public void setSrc(int src)
	{
		this.src = src;
	}

	public int getDest()
	{
		return dest;
	}

	public void setDest(int dest)
	{
		this.dest = dest;
	}

	public int getWeight()
	{
		return weight;
	}

	public void setWeight(int weight)
	{
		this.weight = weight;
	}
	
	@Override
	public String toString()
	{
		return "Edge [src=" + src + ", dest=" + dest + ", weight=" + weight + "]";
	}
	
}
