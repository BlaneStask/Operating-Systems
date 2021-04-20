/*
    Message Mapping Scheme:
    This lab stores messages from a text file in an efficient way
    by taking only words that are not duplicated in other messages
    and reconstructing the message the user wants to view.
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;   

#define NUM_OF_WORDS 100
#define NUM_OF_POSITIONS (NUM_OF_WORDS * 7)

void init_messagecount_arr(int message_count[])
{
    for(int i = 0; i < NUM_OF_WORDS; i++)
    {
        message_count[i] = 0;
    }
}
void init_position_arr(int positions[])
{
    for(int i = 0; i < NUM_OF_POSITIONS; i++)
    {
        positions[i] = 0;
    }
}

inline bool file_exists(const std::string& name)
{
    ifstream f(name.c_str());
    return f.good();
}

int main()
{
    int same_word_counter = 0;
    int message_counter = 0;
    int word_arr_index = 0;
    int word_count = 0;
    int user_num = 0;
    int num_skip = 0;
    int num_of_words = 0;
    int position_index = 0;

    int positions[NUM_OF_POSITIONS];
    int message_count[NUM_OF_WORDS];

    string line;
    string word;
    string name_txt;
    string word_arr[NUM_OF_WORDS];

    char input;

    init_messagecount_arr(message_count);
    init_position_arr(positions);

    cout << "Input name of the text file: ";
    cin >> name_txt;

    // check if file exists
    if (!file_exists(name_txt))
    {
        while (!file_exists(name_txt))
        {
            cout << "File does not exist, please try again: ";
            cin >> name_txt;
        }
    }

    // get file words in array
    ifstream inFile;
    inFile.open(name_txt);
    while (!inFile.eof())
    {
        getline(inFile, line);
        // removing punctuation
        line.erase(remove_if(line.begin(), line.end(), ::ispunct), line.end()); 
        //read word by word from a line
        istringstream iss(line);
        while (iss >> word)
        {
            same_word_counter = 0;
            word_count++;
            for (int i = 0; i < NUM_OF_WORDS; i++)
            {
                // duplicate
                if (word == word_arr[i])
                {
                    same_word_counter++; 
                    break;
                }
            }
            // new word and fits in array size
            if (same_word_counter == 0 && word_arr_index < NUM_OF_WORDS)
            {
                word_arr[word_arr_index] = word;
                word_arr_index++;
            }
        }
        // number of words per line/message
        if (message_count[message_counter] == 0 && word_count != 0)
        {
            message_count[message_counter] = word_count;
        }
        message_counter++;
        word_count = 0;
    }
    inFile.close();

    // get positions
    ifstream infile;
    infile.open(name_txt);
    while (!infile.eof())
    {
        getline(infile, line);
        // removing punctuation
        line.erase(remove_if(line.begin(), line.end(), ::ispunct), line.end()); 
        //read word by word from a line
        istringstream iss(line);
        while (iss >> word)
        {
            // empty, available index
            if (positions[position_index] == 0 && position_index < NUM_OF_POSITIONS)
            {
                for (int j = 0; j < NUM_OF_WORDS; j++) 
                {
                    // get positions by the word array locations
                    if (word == word_arr[j])
                    {
                        positions[position_index] = j; 
                        break;
                    }
                }
            }
            position_index++;
        }
    }
    infile.close();

    // until user quits
    while (input != 'Q' || input != 'q')
    {
        num_skip = 0;
        num_of_words = 0;

        cout << "To Continue (Press C)\n";
        cout << "To Quit (Press Q)\n";
        cin >> input;
        if (input == 'Q' || input == 'q')
        {
            break;
        }
        // valid check
        else if (input != 'Q' && input != 'q' && input != 'C' && input != 'c')
        {
             while (input != 'Q' && input != 'q' && input != 'C' && input != 'c')
            {
                cout << "Key Press is not valid, please try again: ";
                cin >> input;
            }
        }

        cout << "\nInput the message number to display: ";
        cin >> user_num;
        // valid check
        if (user_num < 1 || user_num > message_counter)
        {
            while (user_num < 1 || user_num > message_counter)
            {
                cout << "Message number is not valid, please try again: ";
                cin >> user_num;
            }
        }

        // construct message, get number of messages to skip
        if (user_num == 1)
        {
            num_skip = 0;
        }
        else
        {
            for (int i = 0; i < user_num - 1; i++)
            {
                num_skip += message_count[i];
            }
        }
        num_skip--;

        // get number of words in message
        num_of_words = message_count[user_num - 1];
        cout << "Message: ";
        for (int i = 1; i <= num_of_words; i++)
        {
            // last word, no space
            if (i == num_of_words)
            {
                cout << word_arr[positions[num_skip + i]];
            }
            else
            {   
                cout << word_arr[positions[num_skip + i]] << " ";
            }
        }
        // end with period
        cout << "." << "\n\n";
    }
}
