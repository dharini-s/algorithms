#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
#define RIGHT_COST 0
#define DEL_COST 2
#define INSERT_COST 3
#define REPLACE_COST 4

//typedef oper; //define operations right, replace, delete, insert

/*struct list
{
	char val;
	list *next;
};*/
//list *z; //for later
char *z;
int s;
int **d;
int offset=0; //keeping track of size of z

enum operations { Right, Delete, Insert, Replace, First };
operations **oper;

void deleteChar(string &z, int size, int k)
{
	//z.resize(size + offset -1);
	for (int i = k; i<(size+offset); i++) //oh no.. What's the length?
		z[k] = z[k + 1];
	//std::cout << z.capacity() << "\t" << z.size() << endl;
}

void insertChar(string &z, int size, int k, char c)
{
	//std::z.resize(size + offset);
	//int temp = z[k];
	for(int i=k;i<(size+offset);i++)
		z[k + 1] = z[k];
	z[k] = c;
	//std::cout << z.capacity() << "\t" << z.size() << endl;

}

void retrace(ofstream &ofile, string &x, string &y, int m, int n)
{
	z = new char[m + n];
	//std::cout << z.capacity() << "\t" << z.size() << endl;
	//ofstream ofile;
	//ofile.open("C:\\Users\\Lenovo\\Desktop\\EECS 215\\HW4\\output.txt");
	int i = 0, j = 0; 
	int k = 0;
	int costAtK = 0;
	operations op;
	int totalCost = 0;
	//z = x;//she's doing this
	ofile << "Operation\t\t\tz\t\t\tCost\t\t\tTotal" << endl;
	ofile << "=================================================================" << endl;
	ofile << "Initial string\t\t" << x << "\t\t0\t\t0" << endl;
	while (oper[i][j]!=First)//(i >= 0 && j >= 0)
	{
		op = oper[i][j];
		//cout << "Operation: " << op << endl;
		switch (op)
		{
		case 0:			//Right
			ofile << "Right\t\t";
			//cout << z[k] << "\t" << y[j] << endl;
			z[k] = x[i];
			i++; j++;
			k++;
			costAtK = RIGHT_COST; //find totalcost in the end
			break;
		case 1:			//Delete
			ofile << "Delete\t\t";
			i++;
			//offset++;
			costAtK = DEL_COST;
			break;
		case 2:			//Insert
			ofile << "Insert\t\t";
			//cout << z[k] << "\t" << y[j] << endl;
			z[k] = y[j];
			j++;
			k++;
			//offset++;
			costAtK = INSERT_COST;
			break;
		case 3:		//Replace
			ofile << "Replace\t\t";
			//cout << z[k] << "\t" << y[j] << endl;
			z[k] = y[j];
			i++; j++;
			k++;
			costAtK = REPLACE_COST;
			break;
		default:
			cout << "Error!"<<endl;
			return;
		}
		totalCost += costAtK;
		//cout << "Total cost" << totalCost << endl;
		/*if (op != Delete)
			k++;		////recheck this!*/
		//cout << "Z is: ";
		//ofile.width(m);
		
		for (int p = 0; p < k; p++)
			ofile << z[p];
		ofile << "*";
		for (int q = i; q < m; q++)
			ofile << x[q];
		ofile << "\t\t" << costAtK << "\t\t" << totalCost << endl; 
		//cout << endl;
		/*for (int p = n-1; p >k ; p--)
			cout << z[p];
		cout << "_";
		for (int q = k; q >=0; q--)
		{
			//if(q<n)
				cout << x[q];
		}
		cout << endl;*/
	}

	//ofile << "Operation" << "\t\t" << z << "\t\t" << "Cost" << "\t\t" << totalCost << endl;
	//delete z;
	delete z;
	ofile.close();
}
void editDistance(ofstream &ofile,string &x, string &y, int &m, int &n)
{
	
	int i, j, min;
	//int m1 = m + 1;	//adjusting indices for d
	//int n1 = n + 1;	//to include 0th operation
	int CRt, CD, CI, CRp;

	d = new int*[m+1];

	for (int i = 0; i < m+1; i++)
	{
		d[i] = new int[n+1];
	}
	oper = new operations*[m+1];
	for (int i = 0; i < m+1; i++)
	{
		oper[i] = new operations[n+1];
	}

	for (int i = 0; i < m; i++)
	{
		d[i][n] = (m-i)*DEL_COST; //check this
		//cout << d[i][0];//this is okay
		oper[i][n] = Delete;
	}
	for (int j = 0; j < n; j++)
	{
		d[m][j] = INSERT_COST*(n-j);
		oper[m][j] = Insert;
	}
	d[m][n] = 0;
	oper[m][n] = First;
	//cout << d[22][17];*/

	for (i = m-1; i >=0 ; i--)
	{
		for (j = n-1; j >=0; j--)
		{
			//if(x[i]==y[j])
			operations op;
			CRt = d[i+1][j+1] + RIGHT_COST;
			CD = d[i+1][j] + DEL_COST;
			CI = d[i][j+1] + INSERT_COST;
			CRp = d[i+1][j+1] + REPLACE_COST;
			min = CRt;
			op = Right;
			//cout << x[i] << "\t" << y[j] << endl;
			if (x[i] != y[j])
			{
				min = CRp;
				op = Replace;
			}
			/*else
				op = Right;*/
			if (min > CD)
			{
				min = CD;
				op = Delete;
			}
			if (min > CI)
			{
				min = CI;
				op = Insert;
			}
			d[i][j] = min;
			oper[i][j] = op;
		}
		//cout << i << "\t" << j<<endl;
	}
	cout << "Edit distance is " << d[0][0] << endl;
	retrace(ofile,x,y,m,n);
	for (int i = 0; i < m+1; i++)
	{
		delete[] d[i];
		delete[] oper[i];
	}
	delete[] oper;
	delete[] d;
}

//void replaceChar();

int main(int argc, char* argv[])
{
	int m, n;
	string x, y;
	ifstream ifile;
	ofstream ofile;
	if (argc == 2)
	{
		ifile.open(argv[1]);
		ofile.open(argv[2]);
	}
	else
		cout << "Please enter the correct number of arguments.";
	while (!ifile.eof()) //do a proper check
	{
		string len1, len2;
		//ifile >> m;
		getline(ifile, len1);
		getline(ifile, x);
		getline(ifile, len2);
		getline(ifile, y);
		m = stoi(len1);
		n = stoi(len2);
	}
	//cout << m << x << endl;
	//cout << n << y << endl;
	editDistance(ofile, x, y, m, n);
	ifile.close();
	ofile.close();
}