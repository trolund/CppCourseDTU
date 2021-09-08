#include <iostream>
#include <vector>

using namespace std;

struct Command {
    string command;
    int value;
};

vector<Command> loadCommands (vector<string> s) {
    vector<Command> result;

    for(int i = 0; i < s.size(); i+=2){

        string command = s[i];
        int num = -1;

        if(command != "quit"){
            num = stoi(s[i+1]);
        }

        Command c = Command();
        c.command = command;
        c.value = num;

        result.push_back(c);
    }

    return result;
}

vector<string> getNumbers(string s){
    string delimiter = " ";
    vector<string> result;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    return result;
}

int main() {
    string input;
    int *memory = new int[1000];
    getline(cin, input);
    vector<Command> commands = loadCommands(getNumbers(input));

    for (auto & c : commands) {
        try {
            if(c.command == "quit"){
                break;
            }
            if(c.command == "add"){
                memory[c.value]++;
            }
            if(c.command == "del" && memory[c.value] > 0){
                memory[c.value]--;
            }
            if(c.command == "qry"){
                if(memory[c.value] > 0){
                    cout << "T";
                }else{
                    cout << "F";
                }
            }
        }
        catch(const std::ios_base::failure & readLineException) {
            return 10;
        }
    }

    return 0;
}



