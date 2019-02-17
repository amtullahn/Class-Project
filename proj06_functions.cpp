#include "proj06_functions.h"
#include <iostream>
#include<sstream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::setprecision;
#include<string>
using std::string; using std::getline; using std::to_string;
//getline used to read each line of file as a 
 //to_string converts int to string
#include <stdio.h> 
#include <math.h>   
#include <ctype.h>
#include<vector> 
using std::vector;
#include<fstream> //used to read the file
using std::ifstream;
#include<cctype>

vector<vector<int>> read_file(const string &fname) {
	//No spaces on a row between each number. 
	//read each line of the file in as a string
	//convert each character to an integer
	//push it back onto the row of the 2D vector.
	//Do it for each row.
	
	ifstream proj06_text(fname);
	//myfile.open("proj06_text.txt");
	string some_char; // t
	vector<vector<int>> new_str;

	if (proj06_text.is_open()) { //we want to loop over the string and convert chars in strings 
		while (getline(proj06_text, some_char)) { //reads each line in the file as a string
			vector<int> some_int;

			for (int count = 0; count < some_char.size(); count++) { //converts each character to an integer
				int converted_int = some_char[count] - '0'; //this represents each indexed character in the string converted to an int
				some_int.push_back(converted_int); //pushes it back to the string
			}
			if (some_int.size() > 0) {
				new_str.push_back(some_int); //pushes it back to the row of the 2D vector
			}
		}
	}
	return new_str;
}

vector<int> get_row(const vector<vector<int>> &v, int row) {
	//use for loop to iterate over the rows 
	vector<int> new_str;
	for (auto element : v[row]){ //iterates over the rows in the vector
		new_str.push_back(element); //pushes each element into the vector from the back 
	}
return new_str;
}

vector<int> get_column(const vector<vector<int>> &v, int col) {
	vector<int> vector_col;
	for (auto r : v) { //iterates through the vector
		int new_column = r[col];  //index for each column element in the row
		vector_col.push_back(new_column);
	}
return vector_col; 
}

int col_to_int(const vector<vector<int>> & v, size_t col) {

	vector<int> column = get_column(v, col);
	int sum = 0; 
	int element = 0;
	int exponent = 0;
	for (int count = column.size() - 1; count > 0; count--) { //you start from the last column and iterate through the column 
		element = column[count] * pow(2, exponent); //multiply the column by whether there is a 1 or 0 in each col, row 
		sum += element; //if there are any ones in the column you add those elements and make a sum
		exponent++; // increases the power each time by 1 so the loop can go through the next column
	}
	return sum;
}

string get_time(const vector<vector<int>> & v) { //this is to get the time from the matrix
 
string zero = "0";

string hour = "";
 int first_part = col_to_int(v, 4); //this is the digit you get in the 4th column that represents the hour
 hour = to_string(first_part);
 if (first_part <= 9) { //if it's any single digit number, a zero will be added before it
	 hour = zero + hour; //padding
 }

 string minute = "";
 int second_part = col_to_int(v,1); // this is the digit you get in the 2nd column that represents the minute
 minute = to_string(second_part);
 if (second_part <= 9) {
	minute = zero + minute; //padding
 }
 string final_time = ""; 
 final_time = hour + ":" + minute; // concatenate to get the "hour:minute" formatted time 
 return final_time;
}

string get_date(const vector<vector<int>> & v) { //this is to get the date from the matrix
string zero = "0";
//month/date/year

string month = "";
int first_part = col_to_int(v, 6); //this is the digit you get in the 6th column that represents the month
	month = to_string(first_part);
	if (first_part <= 9) { // if it's any digit less than 10, a zero will be added in front 
		month = zero + month; //padding 
	}

string day = "";
int second_part = col_to_int(v, 5); // this is the digit you get in the 2nd column that represents the day
	day = to_string(second_part);
	if (second_part <= 9) {
		day = zero + day; //padding
	}
string year = "";
int third_part = col_to_int(v, 7); // this is the digit you get in the 2nd column that represents the year
	year = to_string(third_part);
	if (third_part <= 9 ) {  // if it's a yeear number less than 9, a 200 will be added infront of it 
		year = "200" + year; //padding
	}
	else if (third_part >= 10 and third_part <= 99){ //accounts for if there's a 2 digit number in the year, so if you have 2018
		year = "20" + year; //a 20 is added infront of the 2 digit number in the year
	}

string final_date = "";
final_date = month + "/" + day + "/" + year; // concatenate to get the month/date/year formatted time 
return final_date;
}


string get_serial(const vector<vector<int>> & v) { //this is to get the serial number from the matrix
	//13,12,11,10
	string zero = "0";
	
	string column_14 = "";
	int first_part = col_to_int(v, 13); //this integer you get int the 14th volumn
	column_14 = to_string(first_part);
	if (first_part <= 9) {
		column_14 = zero + column_14; //padding 
	}

	string column_13 = "";
	int second_part = col_to_int(v, 12); // this integer you get in the 13th column
	column_13 = to_string(second_part);
	if (second_part <= 9) {
		column_13 = zero + column_13; //padding
	}
	string column_12 = "";
	int third_part = col_to_int(v, 11); // this integer you get in the 12th column
	column_12 = to_string(third_part);
	if (third_part <= 9) {
		column_12 = zero + column_12; //padding
	}
	string column_11 = "";
	int fourth_part = col_to_int(v, 10); // this integer you get in the 11th column
	column_11 = to_string(fourth_part);
	if (fourth_part <= 9) {
		column_11 = zero + column_11; //padding
	}

	string final_date = "";
	final_date = column_14 + column_13 + column_12 + column_11; // concatenate to get the serial number formatted time 
	return final_date;
}

string check_column_parity(const vector<vector<int>> & v, int col) { 
	vector<int> column = get_column(v, col);
	string new_str = "";
	int bit_parity = column[0];
	int count_parity = 0;
	string const_str = "1:";
	string bit_const_str = "0:";
	string boolean_string;

	for (int ones_count = 1; ones_count < column.size(); ones_count++) { //this loop adds all the 1s together in the column
		if (column[ones_count] == 1) {
			count_parity++; //increments the ones count each time the column goes through the loop   
		}
	}
			if (count_parity % 2 == 0) { // part 2 checking if it returns odd or even 
				new_str = new_str + const_str;
				if (bit_parity == 1) { //returns true if the bit parity equals to the column parity
					boolean_string = "true";
				}
				else {
					boolean_string = "false"; //returns false if the bit parity does not equal to the column
				}
			}
			else {
				new_str = new_str + bit_const_str;
				if (bit_parity == 0) { // this is checking if it returns odd  
					boolean_string = "true"; 
				}
				else {
					boolean_string = "false";
				}
			}
			
			string final_str = to_string(count_parity) + ":" + boolean_string; //concatenates the column 1 parity count and the true or false of parity
			new_str = new_str + final_str;
			return new_str;
			//returns column_parity: column_1's_count: true or false if parity of the matrix and the count match
}

string check_row_parity(vector<vector<int>> & v, int row) {
	vector<int> new_row = get_row(v, row);
	string new_str = "";
	int bit_parity = new_row[0];
	int count_parity = 0;
	string const_str = "1:"; //shows parity bit is set(1)
	string bit_const_str = "0:"; //shows parity bit is set(0)
	string boolean_string;

	for (int ones_count = 1; ones_count < new_row.size(); ones_count++) { //this loop adds all the 1s together in the row
		if (new_row[ones_count] == 1) {
			count_parity++;
		}
	}
	// part 2 checking if it returns odd or even 
	if (count_parity % 2 == 0) { //checking for evens
		new_str = new_str + const_str;
		if (bit_parity == 1) { //returns true if the bit parity equals to the row parity
			boolean_string = "true";
		}
		else {
			boolean_string = "false"; //returns false if the bit parity does not equal to the row
		}
	}
	else {
		new_str = new_str + bit_const_str;
		if (bit_parity == 0) { //checking for odds
			boolean_string = "true";
		}
		else {
			boolean_string = "false";
		}
	}

	string final_str = to_string(count_parity) + ":" + boolean_string;
	new_str = new_str + final_str;
	return new_str;
	//returns row_parity: row_1's_count: true or false if parity of the matrix and the count match


}