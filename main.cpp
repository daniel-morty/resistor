#include <iostream>
#include <map>

using namespace std;

#define black	0
#define brown	1
#define red		2
#define orange	3
#define yellow	4
#define green	5
#define blue	6
#define violet	7
#define purple	7
#define	grey	8 
#define white	9

int main(int argc, char *argv[]){
	map<string, int> color_to_num;
	map<string, int>::iterator it;
	map<int, string> num_to_color;
	map<int, string>::iterator itt;

	int sig_fig_table[] = {0,1,2,3,4,5,6,7,8,9};
	int multiplier[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

	color_to_num.insert( std::pair<string, int> ("black",	0));
	color_to_num.insert( std::pair<string, int> ("brown",	1));
	color_to_num.insert( std::pair<string, int> ("red",		2));
	color_to_num.insert( std::pair<string, int> ("orange",	3));
	color_to_num.insert( std::pair<string, int> ("yellow",	4));
	color_to_num.insert( std::pair<string, int> ("green",	5));
	color_to_num.insert( std::pair<string, int> ("blue",	6));
	color_to_num.insert( std::pair<string, int> ("violet",	7));
	color_to_num.insert( std::pair<string, int> ("purple",	7));
	color_to_num.insert( std::pair<string, int> ("grey",	8));
	color_to_num.insert( std::pair<string, int> ("white",	9));

	num_to_color.insert( std::pair<int, string> (0, "black" ));
	num_to_color.insert( std::pair<int, string> (1, "brown"	));
	num_to_color.insert( std::pair<int, string> (2, "red"	));
	num_to_color.insert( std::pair<int, string> (3, "orange"));
	num_to_color.insert( std::pair<int, string> (4, "yellow"));
	num_to_color.insert( std::pair<int, string> (5, "green" ));
	num_to_color.insert( std::pair<int, string> (6, "blue"	));
	num_to_color.insert( std::pair<int, string> (7, "violet"));
	num_to_color.insert( std::pair<int, string> (7, "purple"));
	num_to_color.insert( std::pair<int, string> (8, "grey"	));
	num_to_color.insert( std::pair<int, string> (9, "white"	));


	//calculate value
	int resistor_value = 0;
	int multiply = 10;
	string resistor_color;

	if(argc <= 1){ //nothing was entered
		cout << "nothing to evaluate was entered" << endl;

	} else if(argc > 2){ //colors were entered
		//needed values are argv[1,2,3]
		for(int i=1; i<=3; i++){
			it = color_to_num.find(argv[i]);
			if(it == color_to_num.end()){
				//element not in list
				cout << "invalid color" << endl;
				return 1;
			}
			
			if (i < 3){
				resistor_value += it->second * multiply;
				multiply = 1;
			}
			else{
				resistor_value *= multiplier[it->second];
			}
		}
		cout << resistor_value << endl;	

	} else{ // a value was entered
		
		for(int i=0; i<2; i++){
			itt = num_to_color.find(int(argv[1][i] - 48));
			if(itt != num_to_color.end()){
				cout << itt->second << " ";
			} else {
				cout << "invalid digit" << endl;
				return 1;
			}
		}
		//calculate multiplier
		int value = atoi(argv[1]);
		//cout << "value: " << value << endl;
		int mul = 0;
		while (value >= 100){
			value /= 10;
			mul ++;
			
		}
		itt = num_to_color.find(mul);
		if(itt != num_to_color.end()){
			cout << itt->second << endl;
		}

	}
		
	

	return 0;
}
