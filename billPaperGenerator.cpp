// shop bill paper generator

#include<bits/stdc++.h>
using namespace std;


// execution of code starts here
int main(){
	
	// input file stream
	ifstream file;
	file.open("bill.csv"); 
	
	// output file stream
	ofstream of;
	of.open("output.txt");
	
	// name of shop and address of shop
	string str, adr;
	getline(file, str);
	getline(file, adr);
	
	// getting input as tax
	string tax;
	getline(file, tax);
	
	//erasing the last comma from the string
	str.erase(str.length()-1);
	adr.erase(adr.length()-1);
	
	
	// printing the shop and address of the shop
	of << "\t\t"<<str<<"\n";
	of<<"\t"<<adr<<"\n";
	of<<" --------------------------------------\n";
	of<< " Purchased Items : \n";
	
	// initial item no. 1
	int i = 1; 
	
	// total and gst 
	float total = 0;
	float gst = atof(tax.c_str());
	
	
	// string s
	string s;
	
	

	while(getline(file, s)){
		
		//if length of string is 1, then only ',' comma will be there. so continue to take next input.
		if (s.length() == 1) continue;
		
		// vector containing the strings
		vector<string> v;
 
	    stringstream ss(s);
	 
	    while (ss.good()) {
	        string substr;
	        getline(ss, substr, ',');
	        
	        // if substr length is zero then there is no item there.
	        if (substr.length())
	        	v.push_back(substr);
		}

		
		if (v.size() > 1){
			
			// converting string to flaat.
			float x = atof(v[1].c_str());
			total += x;  // increment total by x
			
			// displaying item with their price
			of << i++ <<"). "<<left<<setw(12)<<v[0]<<right << setw(20) << x << endl;
			
		}
	
		
	}
	
	//displaying total and tax
	of<<" --------------------------------------\n";
	of << " "<< left << setw(12) << "Total : "<<right << setw(23)<<total<<endl;
	
	gst = (float)12/100 * total;  // calculating tax.
	
	of << " "<< left << setw(12) << "Tax : "<<right << setw(23)<< gst <<endl;
	
	of<<" --------------------------------------\n";
	
	// Total payment to be done.
	of << " You have to Pay : "<<total + gst<<endl;
	
	// close output and input file.
	of.close();
	
	file.close();
	
	// open a output file once the bill is made so user can print the bill.
	
	// relative path for output.txt
	string FULL_TXT_PATH = ".\\output.txt" ;
	
	// path for the program in which the file will be opened.
    const string program = "C:\\windows\\system32\\notepad.exe" ;
	 
    const char quote = '\'' ; // required if the path contains space
    
    const std::string command = program + ' ' + quote + FULL_TXT_PATH + quote ;

    std::system( command.c_str() ) ;
	
	return 0;
}
