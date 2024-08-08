#include <iostream>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

map<char, int> charMap;

class Vigenere
{
protected:
    string Key, Text, Cyphertext, Keyword, Encrypted, Decrypted;
    char **arr;
    char **arr1;

public:
    Vigenere()
    {
        Key = "";
        Keyword = "";
        Text = "";
        Cyphertext = "";
        arr = nullptr;
        arr1 = nullptr;
    }

    ~Vigenere()
    {
        for (int i = 0; i < 40; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;

        for (int i = 0; i < 40; i++)
        {
            delete[] arr1[i];
        }
        delete[] arr1;
    }

    void Map()
    {

        string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? ";

        for (int i = 0; i < characters.size(); ++i)
        {
            charMap[characters[i]] = i + 1;
        }
    }

    void input()
    {
        cout << "The key for Vigenere table can contain NON-repeating letters, numbers or special symbols (,  .  ? ) and spaces" << endl;
        cout << "Enter the key for a custom Vigenere table: " << endl;
        getline(cin, Key);
        for (size_t i = 0; i < Key.length(); i++)
        {
            if (isalpha(Key[i]))
            {
                Key[i] = toupper(Key[i]);
            }
        }
        cout << Key << endl;

        cout << "The text can only contain alphabets from the english language, numbers and the following special symbols (.  ,   ?) and spaces" << endl;
        cout << "Enter the Text you want to encrypt: " << endl;
        getline(cin, Text);
        for (int i = 0; i < (Text).length(); i++)
        {
            if (isalpha(Text[i]))
            {
                Text[i] = toupper(Text[i]);
            }
        }

        cout << Text << endl;

        cout << "Enter the keyword for encryption. Longer the key, the better: " << endl;
        getline(cin, Keyword);
        for (int i = 0; i < Keyword.length(); i++)
        {
            if (isalpha(Keyword[i]))
            {
                Keyword[i] = toupper(Keyword[i]);
            }
        }
        cout << Keyword << endl;
    }

    void input(string a)
    {
        cout << "The key for Vigenere table can contain NON-repeating letters, numbers or special symbols (,  .  ? ) and spaces" << endl;
        cout << "Enter the key for a custom Vigenere table: " << endl;
        getline(cin, Key);
        for (size_t i = 0; i < Key.length(); i++)
        {
            if (isalpha(Key[i]))
            {
                Key[i] = toupper(Key[i]);
            }
        }
        cout << Key << endl;

        cout << "The text can only contain alphabets from the english language, numbers and the following special symbols (.  ,   ?) and spaces" << endl;
        cout << "Enter the cyphertext you want to decrypt: " << endl;
        getline(cin, Cyphertext);
        for (int i = 0; i < (Cyphertext).length(); i++)
        {
            if (isalpha(Cyphertext[i]))
            {
                Cyphertext[i] = toupper(Cyphertext[i]);
            }
        }

        cout << Text << endl;

        Keyword = a;
        for (int i = 0; i < Keyword.length(); i++)
        {
            if (isalpha(Keyword[i]))
            {
                Keyword[i] = toupper(Keyword[i]);
            }
        }
        cout << Keyword << endl;
    }

    void Vigenere_table()
    {
        int size = 40;
        char Temp[size];
        const char Temp1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', ' '};

        for (int i = 0; i < Key.length(); i++)
        {
            Temp[i] = Key[i];
        }

        int index = Key.length();
        for (int i = 0; i < size; i++)
        {
            bool set = false;
            for (int j = 0; j < Key.length(); j++)
            {
                if (Key[j] == Temp1[i])
                {
                    set = true;
                    break;
                }
            }
            if (set != true)
            {
                Temp[index++] = Temp1[i];
            }
        }

        // Allocate memory for Vigenère table
        arr = new char *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new char[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k < size; k++)
            {
                arr[i][k] = Temp[k];
            }

            char store = Temp[0];
            for (int x = 0; x < size - 1; x++)
            {
                Temp[x] = Temp[x + 1];
            }
            Temp[size - 1] = store;
        }

        // Print Vigenère table
        cout << "Your Vigenere Table is: " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << arr[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }
    void Vigenere_table(string Key)
    {
        int size = 40;
        char Temp[size];
        const char Temp1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', ' '};

        for (int i = 0; i < Key.length(); i++)
        {
            Temp[i] = Key[i];
        }

        int index = Key.length();
        for (int i = 0; i < size; i++)
        {
            bool set = false;
            for (int j = 0; j < Key.length(); j++)
            {
                if (Key[j] == Temp1[i])
                {
                    set = true;
                    break;
                }
            }
            if (set != true)
            {
                Temp[index++] = Temp1[i];
            }
        }

        // Allocate memory for Vigenère table
        arr = new char *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new char[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k < size; k++)
            {
                arr[i][k] = Temp[k];
            }

            char store = Temp[0];
            for (int x = 0; x < size - 1; x++)
            {
                Temp[x] = Temp[x + 1];
            }
            Temp[size - 1] = store;
        }

        // Print Vigenère table
        cout << "Your Vigenere Table is: " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << arr[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }

    void Encryption()
    {

        arr1 = new char *[2];
        for (int i = 0; i < 2; i++)
        {
            arr1[i] = new char[Text.length()];
        }

        for (int i = 0; i < Text.length(); i++)
        {
            arr1[0][i] = Text[i];
        }

        for (int i = 0; i < Text.length(); i++)
        {
            arr1[1][i] = Keyword[i % (Keyword.length())];
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < Text.length(); j++)
            {
                cout << arr1[i][j];
            }
            cout << endl;
        }

        Encrypted.resize(Text.length());

        for (int i = 0; i < Text.length(); i++)
        {

            Encrypted[Text.length()];
            int a, b;
            a = charMap[arr1[0][i]] - 1;
            b = charMap[arr1[1][i]] - 1;
            Encrypted[i] = arr[b][a];
        }

        cout <<"-----> " <<Encrypted <<" <-----"<< endl;
        // Calling the destructor to clean the storage.
        this->~Vigenere();
    }

    void Decryption()
    {

        string s;
        cout << "Enter the keyword for decryption. Longer the key, the better: " << endl;
        getline(cin, s);
        input(s);
        Vigenere_table(Key);

        arr1 = new char *[2];
        for (int i = 0; i < 2; i++)
        {
            arr1[i] = new char[Cyphertext.length()];
        }

        for (int i = 0; i < Cyphertext.length(); i++)
        {
            arr1[0][i] = Cyphertext[i];
        }

        for (int i = 0; i < Cyphertext.length(); i++)
        {
            arr1[1][i] = Keyword[i % (Keyword.length())];
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < Cyphertext.length(); j++)
            {
                cout << arr1[i][j];
            }
            cout << endl;
        }

        Decrypted.resize(Cyphertext.length());

        for (int i = 0; i < Cyphertext.length(); i++)
        {

            int b;
            b = charMap[arr1[1][i]] - 1;
            for (int j = 0; j < 40; j++)
            {

                char Tempchar;
                if (arr[b][j] == arr1[0][i])
                {
                    for (const auto &pair : charMap)
                    {
                        if (pair.second == j+1)
                        {
                            Tempchar = pair.first;
                            break;
                        }
                    }

                    Decrypted[i] = Tempchar;
                }
            }
        }

        

        cout <<"-----> " <<Decrypted <<" <-----"<< endl;

        // Calling the destructor to clean the storage.
        this->~Vigenere();
    }
};

int main()
{
    Vigenere a;
    a.Map();
    string s;
    cout << "For Encrypting a text, type E." << endl
         << "For Decrypting a cyphertext, type D : " << endl;
    getline(cin, s);

    if (s == "D")
    {
        a.Decryption();
    }
    else if (s == "E")
    {
        a.input();
        a.Vigenere_table();
        a.Encryption();
    }
    else
    {
        cout << "Enter a valid query." << endl;
    }

    return 0;
}