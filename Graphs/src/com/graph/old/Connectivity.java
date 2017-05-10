package com.graph.old;
import java.util.List;
import java.util.LinkedList;

public class Connectivity
{
	public class Node
	{
		List<Node> children;
	}

	public List<Node> isConnected(Node root, List<Node> all)
	{
		//Using DFS
		List<Node> visited = new LinkedList<Node>();
		List<Node> unvisited = new LinkedList<Node>();
		if(root == null)
			return null;
		visited.add(root);
		
		for(int i=0; i<root.children.size(); i++) //what size should be checked?
		{
			if(!visited.contains(root.children.get(i)))
			{
				
			}
					
		}
		return unvisited;
	}
	public static void main(String[] args)
	{
		Connectivity conn = new Connectivity();
		//Node node = 
	}

}
