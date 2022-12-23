#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

struct message {
	char text[20];
	message() {};
	message(string s) {
		if (s.length() > 20) {
			cout << "Error. Mistacke in creating of massage";
			return;
		}
		strcpy(text, s.c_str());
	}
	char* get_text() {
		return text;
	}
	friend ostream& operator <<(ostream& out, message& m) {
		out.write((char*)&m, sizeof(m));
		return out;
	}
	friend istream& operator >>(istream& in, message& m) {
		in.read((char*)&m, sizeof(m));
		return in;
	}
};
