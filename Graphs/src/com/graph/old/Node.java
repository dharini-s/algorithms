package com.graph.old;
import java.util.LinkedList;
import java.util.List;

/*
 * CLRS representation where the index of the outer list is the value of the vertex
 */
public class Node
{
	List<List<Integer>> children;
	 
	public Node()
	{
		//Empty
	}
//	public void addEdge(Integer from, Integer to)
//	{
//		
//	}
	
//	public void addEdge(Integer val)
//	{
//		if(children == null)
//		{
//			children = new LinkedList<List<Integer>>();
//		}
//		List<Integer> vertex = new LinkedList<Integer>();
//		vertex.add(val);
//	}
	
	public void addEdge(List<Integer> list)
	{
		if(children == null)
		{
			children = new LinkedList<List<Integer>>();
		}
		children.add(list);
	}
	
	@Override
	public String toString()
	{
		if(children != null)
		{
			for(int i=0; i<children.size(); i++)
			{
				List<Integer> vertex = children.get(i);
				for(int j=0; j<vertex.size(); j++)
				{
					System.out.print(vertex.get(j)+" ");
				}
				System.out.println();
			}
		}
		return null;//actually should throw an exception
	}
	public static void main(String args[]) //look up argc and argv
	{
		Node graph = new Node();
		List<Integer> intList = new LinkedList<Integer>();
		//For vertex 1
		intList.add(2);
		intList.add(3);
		graph.addEdge(intList);
		
		//For vertex 2
		intList = new LinkedList<Integer>();
		intList.add(4);
		graph.addEdge(intList);
		
		//For vertex 3
		intList = new LinkedList<Integer>();
		intList.add(2);
		graph.addEdge(intList);
		
		//For vertex 4
		intList = new LinkedList<Integer>();
		intList.add(3);
		graph.addEdge(intList);
		
		graph.toString();
	}
}
