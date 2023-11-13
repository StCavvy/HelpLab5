#include <string>
#include <iostream>

using namespace std;
int WordSize(string input, int first_letter);
int FindFirstLetter(string input);
string CrossWord(string input, int first_letter, int word_size);


int main()
{
    string input_string;
    cout << "Enter your string : ";
    cin >> input_string;
    string input_copy = input_string;
    
    int first_letter = 0;
    int word_size = 0;

    int total_size = 0;
    int words_count = 0;
    double total_percentage = 0;
    bool check = false;

    while (check == false)
    {
        first_letter = FindFirstLetter(input_copy);
        if (first_letter == -1) 
        {
            check = true;
            break;
        }

        word_size = WordSize(input_copy, first_letter);
        if (word_size > 0)
        {
            total_size += word_size;
            words_count++;
        }

        input_copy = CrossWord(input_copy, first_letter, word_size);

        first_letter = 0;
        word_size = 0;
    }

    total_percentage = (100 / input_copy.length()) * total_size;

    cout << "Total words count : " << words_count << endl;
    cout << "Total words size compared to total string size : " << total_percentage << "%" << endl;
    cout << "Your string where all words are crossed out : " << input_copy;
}


int WordSize (string input, int first_letter) 
{

    int letters_in_row = 0;

    for (int i = first_letter; ; i++) 
    {
        if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
        {
            letters_in_row++;
        }
        else break;
    }

    if (letters_in_row > 1)
    {
        return letters_in_row;
    }
    else 
    {
        return 0;
    }
}

int FindFirstLetter(string input)
{
    int first_letter = -1;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
        {
            first_letter = i;
            break;
        }
    }

    return first_letter;
}

string CrossWord(string input, int first_letter, int word_size)
{
    string output;
    for (int i = first_letter; i < first_letter + word_size; i++) 
    {
        input[i] = '*';
    }
    output = input;
    return output;
}