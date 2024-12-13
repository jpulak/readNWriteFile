# readNWriteFile
General Description:
Write a program that will read a file containing sales data and write a bar chart to represent the data read to a file named “saleschart.txt”.

The program will ask the user for the name of the text file containing the sales data.

The store number must be stored in a variable of type unsigned int. The sales value must be stored in a variable of type long long int.

Your program should have the following general flow:
```
prompt for the input file name 
read in the file name
open the input file for this file name
if the file opens successfully
     open the output file ("saleschart.txt")
     if the file opens successfully
          while (readFile record (store number and sales for store))
               process record read
          end while
          close the input and output files
     otherwise, display a message if the output file does not open, close the input file
otherwise, display a message if the input file does not open
```
The Details
The Format of the Input Files
Each line of the text file containing the sales information has a store number followed by one or more space characters and then the sales amount followed by a newline. There will be zero or more of these input pairs in the file.

Here are the contents of a sample input text file:
```
1 10000
2 25000
3 37000
4 29000
5 8000
```
The output (to file saleschart.txt) for this input would be:
```
SALES BAR CHART
(Each * equals 5,000 dollars)
Store  1: **
Store  2: *****
Store  3: *******
Store  4: *****
Store  5: *
```
Assuming you have read in valid data AND this is the first sales data being processed, your program should output the headings to the output file, before processing the data. The headings are as follows:
```
SALES BAR CHART
(Each * equals 5,000 dollars)
```
Note: Your program must not write the headings if all of the data in the input file is invalid, or there is not any data in the input file.

If the input file could not be opened display an error message on the screen. Assuming the file named given was sales.txt the second sentence of the error message displayed must be "sales.txt” could not be opened.

The store number is of type unsigned int. Your program must verify that the store number is in the range 1 to 99 (inclusive). Assuming the number read was 110, the second sentence of the error message must be 110 is not in the range 1 through 99.

The sales data is read in as a long long int. If the sales value is less than 0, display an error message on the screen. Assuming the store number is 13, the second sentence of the error message must be Skipped store #13.

You should not write the data to the file when either the store number or sales value was determined to be invalid.

Writing the Bar Chart Information to the File

You will be outputting a string of * characters where each * represents $5,000 in sales for that store. For each 5,000 in sales, you output one *. You do not round up the sales, so sales of $16,000 and sales of $16,999 would both output 3 * characters.

You will write the sales bar chart to the output file.

Assuming a store number of 9 and sales of $16,999, write the following to the output file:
```
Store  9: ***
```
Note that the store width is 2 characters, so the output is:
```
Store yy: *******
```
The yy has a width of two even if the store number is 1 through 9.

When you run your program in your IDE it should look like the following.

Recall in Zylabs, the input will not be displayed, nor will the newline generated when the user hits the enter key.

Sample Output :
```
Please enter the input file name.
salesb.txt
```
Do not forget the newline at the end of the program.

Submitting to Zylabs
Your source file must be named/renamed StoreSalesChart.cpp for submission to Zylabs

You should be creating and thoroughly testing you source code in your IDE before submitting for grading in Zylabs. ZYLABS IS AN AUTO-GRADER. It is not your tester.

When you submit to Zylabs for grading, if you do not pass one or more tests. Pay close attention to the type of test. There are tests to determine if your output starts with specific text, tests to determine if your output ends with specific text, tests to determine if your output contains specific text, and tests to determine if your output exactly matches the expected output.

Depending on the type of test you may get yellow highlighted text when you run the tests. This can be because you are not getting the correct result. It could also be because your formatting does not match what is required. The checking that ZyLabs does is very exacting, and you must match it exactly. More information about what the yellow highlighting can be found in "1.2 zyLab training: Basics".

Reading Text Files
When reading data from a file you need to make sure you are checking for end of file properly.

The general method shown in the Gaddis textbook is:
```
ifstream inputFile;

inputFile.open("input.txt");

int num;

if (inputFile)
{
   // the file opened successfully

   while (inputFile >> num)
   {
      // process the num value

      cout << num << endl;
   }

   inputFile.close();
}
else
{
   cout << "The file could not be opened" << endl;
}
```
If you want to read in two values with every read you can simply replace inputFile >> num with something like inputFile >> num1 >> num2 as shown here:
```
   while (inputFile >> num1 >> num2)
   {
      // process the num1 and num2 values

      cout << num1 << " " << num2 <<  endl;
   }
```
Text files are more complicated that they seem. Different operating systems handle text files differently. On Windows lines of text end with \r followed by \n. On Unix (or Linux) the lines end with just \n. On old Macs lines ended with \r but now use the Unix convention. The use of the >> operator takes care of these line ending issues for you.

But it is still more complicated than that. Most text files have every line ending with either \r \n (for Windows) or \n (for Unix/Linux and MacOS) but it is also possible to create a text file where the last line does NOT have the line ending characters. The use of the following code will work for all line endings even when the last line of text input does not end with any line endings.
```
if (inputFile >> num1 >> num2)
{
    // executes only if the read worked
}
```
or
```
while (inputFile >> num1 >> num2)
{
   // executes while the read works
}
```
There are other ways to test for end of file but you have to make sure your code will work for all the cases discussed above. It is STRONGLY recommended that you use the process outlined above.
