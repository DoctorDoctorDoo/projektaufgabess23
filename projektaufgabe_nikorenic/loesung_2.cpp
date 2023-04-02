#include <iostream>
#include <map>
#include <locale>
#include <string>
#include <cctype>
#include <ctype.h>

std::map<char,int> get_frequencies(){
    std::map<char,int> output;
    while(true){
        unsigned char c;
        std::cin >> c;
        if (not std::cin)
        break;
        c = std::toupper(c);
        if(std::isalpha(c)){
            if(output.count(c)){
            output[c]++;
            }else output[c] = 1;
        }
    }
    return output;
}
void print_frequencies(const std::map<char,int>& frequencies){
    double gesamtanzahl;
    std::cout << "\n";
        for(std::pair<char,int> c: frequencies){
            gesamtanzahl = gesamtanzahl + c.second;
            std::cout << c.first << "," << c.second << "   ";
        }
        for(std::pair<char,int> c: frequencies){
            double anteil = c.second/gesamtanzahl;
            std::cout << c.first << ":" << anteil << "%   ";
        }
    std::cout << "\nDie Gesamtanzahl an Buchstaben enthält: " << gesamtanzahl << std::endl;
}

void letter_frequencies(){
    print_frequencies(get_frequencies());
}

int main(){
   letter_frequencies();
}
bool std::isalpha(char c) {
    std::string input_string = "Hallo! Valorant ist cool.";

    for (char c : input_string) {
        if (std::isalpha(c)) {
            std::cout << c;
        }
    }

    return 0;
}

int second() {
    std::string input;
    int uppercase_count = 0;

    std::cout << "Geben Sie eine Zeichenkette ein: ";
    std::getline(std::cin, input);

    for (char c : input) {
        if (std::isupper(c)) {  // Wenn  Buchstabe bereits großgeschrieben
            uppercase_count++;  // erhöhe den Zähler direkt.
        } else if (std::islower(c)) {  // Wenn  Buchstabe klein g,
            uppercase_count++;  // wandle  in Großbuchstaben um
            c = std::toupper(c);
        }
    }

    std::cout << "Anzahl der Großbuchstaben: " << uppercase_count << std::endl;
    std::cout << "Eingabe mit Großbuchstaben: " << input << std::endl;

    return 0;
}
int third() {
    std::string input;
    std::map<char, int> frequency_map;

    std::cout << "Geben Sie Wörter ein: ";
    std::getline(std::cin, input);

    int total_count = 0;
    for (char c : input) {
        if (std::isalpha(c)) {  // Nur Buchstaben
            total_count++;
            c = std::toupper(c);  //  Großbuchstaben umwandeln
            frequency_map[c]++;  // Häufigkeit erhöhen
        }
    }

    std::cout << "Häufigkeiten (in Prozent):\n";
    for (const auto& [c, count] : frequency_map) {
        double percentage = static_cast<double>(count) / total_count * 100.0;
        std::cout << c << ": " << percentage << "%\n";
    }

    return 0;
}