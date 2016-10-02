#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void MergeTheVector(vector<long> & left_vector,vector<long> & right_vector, vector<long> & complete_vector)
{
	  vector<string>::size_type count=left_vector[left_vector.size()-1]+right_vector[right_vector.size()-1];
    left_vector=vector<long>(left_vector.begin(),left_vector.end()-1);
    right_vector=vector<long>(right_vector.begin(),right_vector.end()-1);    
    vector<long>::size_type r=0,l=0; 
		complete_vector.clear();		
    for(vector<long>::size_type i=0;i<right_vector.size()+left_vector.size();i++)
    {
        if(l==left_vector.size())
        {
            complete_vector.insert(complete_vector.end(), right_vector.begin()+r, right_vector.end());
						break;

        }
        else if(r==right_vector.size())
        {
            complete_vector.insert(complete_vector.end(), left_vector.begin()+l, left_vector.end());
						break;
						
        }

        else if(left_vector[l]<right_vector[r])
        {
            complete_vector.push_back(left_vector[l]);
            l++;

        }
        else
        {
            complete_vector.push_back(right_vector[r]);
            count+=left_vector.size()-l;
            r++;
        }
         
    }
    complete_vector.push_back(count);
    
}
void SortByDividingTheVector(vector<long>& input_vector)
{
    if(input_vector.size()>1)
    {
        vector<long>::size_type mid=input_vector.size()/2;    
        vector<long> left_vector(input_vector.begin(),input_vector.begin()+mid);
        vector<long> right_vector(vector<long>(input_vector.begin()+mid,input_vector.end()));        
        SortByDividingTheVector(left_vector);
        SortByDividingTheVector(right_vector);
        MergeTheVector(left_vector,right_vector,input_vector);
    }

    else 
    {				
        input_vector.push_back(0);
    }

}

int main()
{

    vector<long> num_vector;
    ifstream input;
    input.open("s.txt");
    long number;
    while(input>>number)
    {
        num_vector.push_back(number);
    }
    for(vector<long>::size_type i=0; i!=num_vector.size();i++)
            cout<<num_vector[i]<<" ";
    cout<<endl;
   SortByDividingTheVector(num_vector);
		for(vector<long>::size_type i=0; i!=num_vector.size();i++)
            cout<<num_vector[i]<<" ";
    cout<<endl;
    return 0;
}






