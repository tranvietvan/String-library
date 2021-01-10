#include"String.h"

MyString::MyString(){
	s = new char[0];
	s[0] = NULL;
}
void MyString::setstring(char s1[]){
	s = s1;
}
char* MyString::getstring(){
	return s;
}
MyString& MyString::operator=(MyString s1){
	int n = s1.length();
	s = new char[n];
	for (int i = 0; i < n; i++){
		s[i] = s1[i];
	}
	s[n] = NULL;
	return *this;
}
MyString&  MyString::operator=(char* str){
	int n = 0;
	char *c = str;
	while (*c != NULL){
		n++;
		c++;
	}
	s = new char[n];
	for (int i = 0; i < n; i++){
		s[i] = str[i];
	}
	s[n] = NULL;
	return *this;
}
MyString&  MyString::operator=(char c){
	s = new char[2];
	s[0] = c;
	s[1] = '\0';
	return *this;
}
char* MyString::begin(){
	return s;
}
char* MyString::end(){
	return s + length()-1;
}
char* MyString::rbegin(){
	return end();
}
char* MyString::rend(){
	return begin();
}
char* MyString::cbegin(){
	return s;
}
char* MyString::cend(){
	return s + length() - 1;
}
char* MyString::crbegin(){
	return s + length() - 1;
}
char* MyString::crend(){
	return s;
}
size_t MyString::size(){
	return sizeof(char)*length();
}
size_t MyString::max_size() const{
	return 4294967291;
}
void MyString::resize(size_t size1, char x){
	char s1[100000];
	int n = length();
	for (int i = 0; i < n; i++){
		s1[i] = s[i];
	}
	s = new char[size1+1];
	for (int i =n ; i < size1; i++){
		s[i] = x;
	}
	s[size1] = NULL;
}
void MyString::resize(size_t size){
	char s1[100000];
	for (int i = 0; i < size; i++){
		s1[i] = s[i];
	}
	s = new char[size+1];
	for (int i = 0; i < size; i++){
		s[i] = s1[i];
	}
	s[size] = NULL;
}
void MyString::clear(){
	s = new char[0];
	s[0] = NULL;
}
bool MyString::empty(){
	if (length() == 0) return 1;
	return 0;
}
size_t MyString::length(){
	int n = 0;
	char* c = s;
	while (*c != NULL){
		n++;
		c++;
	}
	return n;
}
char& MyString::operator[](size_t pos){
	return s[pos];
}
char& MyString::at(size_t pos){
	return s[pos];
}
char& MyString::back(){
	return s[length() - 1];
}
char& MyString::front(){
	return s[0];
}
MyString& MyString::operator+=(MyString str){
	char s1[100000];
	int l1 = length();
	int l2 = str.length();
	for (int i = 0; i < l1; i++){
		s1[i] = s[i];
	}
	s = new char[l1+l2];
	for (int i = 0; i < l1; i++){
		s[i] = s1[i];
	}
	char* c = str.getstring();
	for (int i = 0; i <l2; i++){
		s[i+l1] = c[i ];
	}
	s[l1+l2] = NULL;
	return *this;
}
MyString& MyString::operator+= (char* s1){
	MyString t;
	t = s1;
	*this += t;
	return *this;
}
MyString& MyString::operator+= (char c){
	MyString t;
	t = c;
	*this += t;
	return *this;
}
MyString& MyString::append(MyString s1){
	*this += s1;
	return *this;
}
MyString& MyString::append(MyString s1, size_t subpos, size_t sublen){
	int len;
	if (subpos + sublen > s1.length()) len = s1.length() - subpos ;
	else len =sublen;
	char* t1 = new char[len];
	for (int i = 0; i < len; i++) t1[i] = s1.getstring()[i + subpos];
	t1[len] = NULL;
	MyString t;
	t = t1;
	*this += t;
	return *this;
}
MyString& MyString::append(char* str){
	MyString t;
	t = str;
	*this += t;
	return *this;
}
MyString& MyString::append(char*str, size_t n){
	char* t;
	t = new char[n];
	for (int i = 0; i < n; i++) t[i] = str[i];
	t[n] = NULL;
	MyString temp;
	temp = t;
	*this += temp;
	return *this;
}
MyString& MyString::append(size_t n, char c){
	char*t = new char[n];
	for (int i = 0; i < n; i++) t[i] = c;
	t[n] = NULL;
	MyString temp;
	temp = t;
	*this += temp;
	return *this;
}
void MyString::push_back(char c){
	append(1, c);
}
MyString& MyString::assign(MyString str){
	*this = str;
	return *this;
}
MyString& MyString::assign(MyString s1, size_t subpos, size_t sublen){
	int len;
	if (subpos + sublen > s1.length()) len = s1.length() - subpos;
	else len = sublen;
	char* t1 = new char[len];
	for (int i = 0; i < len; i++) t1[i] = s1.getstring()[i + subpos];
	t1[len] = NULL;
	MyString t;
	t = t1;
	*this = t;
	return *this;
}
MyString& MyString::assign(char* s){
	*this = s;
	return *this;
}
MyString& MyString::assign(char* s, size_t n){
	char* t;
	t = new char[n];
	for (int i = 0; i < n; i++) t[i] = s[i];
	t[n] = NULL;
	*this = t;
	return *this;
}
MyString& MyString::assign(size_t n, char c){
	char*t = new char[n];
	for (int i = 0; i < n; i++) t[i] = c;
	t[n] = NULL;
	*this = t;
	return *this;
}
MyString& MyString::insert(size_t pos, MyString s1){
	int l1 = length();
	char* t1 = new char[pos];
	char* t2 = new char[l1 - pos];
	for (int i = 0; i < pos; i++) t1[i] = s[i];
	t1[pos] = NULL;
	for (int i = pos; i < l1; i++) t2[i - pos] = s[i];
	t2[l1 - pos] = NULL;
	assign(t1);
	append(s1);
	append(t2);
	return *this;
}
MyString& MyString::insert(size_t pos, MyString s1, size_t subpos, size_t sublen){
	MyString t;
	t.assign(s1, subpos, sublen);
	insert(pos, t);
	return *this;
}
MyString& MyString::insert(size_t pos, char* s1){
	MyString t;
	t = s1;
	insert(pos, t);
	return *this;
}
MyString& MyString::insert(size_t pos, char* s1, size_t n){
	MyString t;
	t.assign(s1,n);
	insert(pos, t);
	return *this;
}
MyString& MyString::insert(size_t pos, size_t n, char c){
	MyString t;
	t.assign(n, c);
	insert(pos, t);
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len){
	int len1;
	if (pos + len > length()) len1 = length() - pos;
	else len1 = len;
	char* t;
	int n = length() - len1;
	t = new char[n];
	for (int i = 0; i < pos; i++) t[i] = s[i];
	for (int i = pos; i < n; i++) t[i] = s[pos+len1];
	t[n] = NULL;
	*this = t;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, MyString s1){
	erase(pos, len);
	insert(pos, s1);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, MyString s1, size_t subpos, size_t sublen){
	erase(pos, len);
	insert(pos, s1, subpos, sublen);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len,char* s1){
	erase(pos, len);
	insert(pos, s1);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, char* s1, size_t n){
	erase(pos, len);
	insert(pos, s1, n);
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c){
	erase(pos, len);
	insert(pos, n, c);
	return *this;
}
void MyString::swap(MyString& s1){
	MyString t;
	t = *this;
	*this = s1;
	s1 = t;
}
void MyString::pop_back(){
	erase(length() - 1, 1);
}
char* MyString::c_str() const{
	return s;
}
char* MyString::data() const{
	return s;
}
size_t MyString::copy(char* s1, size_t len, size_t pos){
	int len1;
	if (pos + len > length()) len1 = length() - pos;
	else len1 = len;
	for (int i = 0; i < len1; i++) s1[i] = getstring()[i + pos];
	s1[len1] = NULL;
	return len1;
}
size_t MyString::find(MyString s1, size_t pos=0){
	for (int i = 0; i < length(); i++){
		if (s[i] == s1.getstring()[0]){
			MyString t;
			t = substr(i, s1.length());
			if (t == s1){
				pos = i;
				break;
			}
		}
	}
	return pos;
}
size_t MyString::find(char* s1, size_t pos = 0){
	MyString ss1;
	ss1 = s1;
	return find(ss1, pos);
}
size_t MyString::find(char* s1, size_t n, size_t pos = -1){
	MyString ss1;
	ss1.assign(s1, n);
	return find(ss1, pos);
}
size_t MyString::find(char c, size_t pos = 0){
	for (int i = 0; i < length(); i++){
		if (s[i] == c){
			pos = i;
			break;
		}
	}
	return pos;
}
size_t MyString::rfind(MyString s1, size_t pos = -1){
	for (int i = length()-1; i >=0; i--){
		if (s[i] == s1.getstring()[s1.length()-1]){
			int x = i - s1.length() + 1;
			MyString t;
			t = substr(x, s1.length());
			if (t == s1){
				pos = i;
				break;
			}
		}
	}
	return pos;
}
size_t MyString::rfind(char* s1, size_t pos = -1){
	MyString ss1;
	ss1 = s1;
	return rfind(ss1, pos);
}
size_t MyString::rfind(char* s1, size_t pos = -1, size_t n){
	MyString ss1;
	ss1.assign(s1, n);
	return rfind(ss1, pos);
}
size_t MyString::rfind(char c, size_t pos=-1){
	for (int i = length()-1; i >=0; i--){
		if (s[i] == c){
			pos = i;
			break;
		}
	}
	return pos;
}
size_t MyString::find_first_of(MyString s1, size_t pos = 0){
	for (int i = 0; i < length(); i++){
		for (int j = 0; j < s1.length(); j++){
			if (s[i] == s1.getstring()[j]){
				pos = i;
				break;
			}
			if (pos != 0) break;
		}
	}
	return pos;
}
size_t MyString::find_first_of(char* s1, size_t pos = 0){
	MyString ss1;
	ss1 = s1;
	return find_first_of(ss1, pos);
}
size_t MyString::find_first_of(char* s1, size_t pos, size_t n){
	MyString ss1;
	ss1.assign(s1, n);
	return find_first_of(ss1, pos);
}
size_t MyString::find_first_of(char c, size_t pos = 0){
	return find(c, pos);
}
size_t MyString::find_last_of(MyString s1, size_t pos=-1){
	for (int i = length(); i >=0; i++){
		for (int j = 0; j < s1.length(); j++){
			if (s[i] == s1.getstring()[j]){
				pos = i;
				break;
			}
			if (pos != 0) break;
		}
	}
	return pos;
}
size_t MyString::find_last_of(char* s1, size_t pos=-1){
	MyString ss1;
	ss1 = s1;
	return find_last_of(ss1, pos);
}
size_t MyString::find_last_of(char* s1, size_t n, size_t pos = -1){
	MyString ss1;
	ss1.assign(s1, n);
	return find_last_of(ss1, pos);
}
size_t MyString::find_last_of(char c, size_t pos = -1){
	return rfind(c, pos);
}
size_t MyString::find_first_not_of(MyString s1, size_t pos = 0){
	for (int i = 0; i < length(); i++){
		for (int j = 0; j < s1.length(); j++){
			if (s[i] != s1.getstring()[j]){
				pos = i;
			}
			else pos = 0;
		}
		if (pos != 0) break;
	}
	return pos;
}
size_t MyString::find_first_not_of(char* s1, size_t pos = 0){
	MyString ss1;
	ss1 = s1;
	return find_first_not_of(ss1, pos);
}
size_t MyString::find_first_not_of(char* s1, size_t pos, size_t n){
	MyString ss1;
	ss1.assign(s1, n);
	return find_first_not_of(ss1, pos);
}
size_t MyString::find_first_not_of(char c, size_t pos = 0){
	for (int i = 0; i < length(); i++){
		if (s[i] != c){
			pos = i;
			break;
		}
	}
	return pos;
}
size_t MyString::find_last_not_of(MyString s1, size_t pos = -1){
	for (int i = length(); i >= 0; i++){
		for (int j = 0; j < s1.length(); j++){
			if (s[i] != s1.getstring()[j]){
				pos = i;
			}
			else pos = 0;
		}
		if (pos != 0) break;
	}
	return pos;
}
size_t MyString::find_last_not_of(char* s1, size_t pos = -1){
	MyString ss1;
	ss1 = s1;
	return find_last_not_of(ss1, pos);
}
size_t MyString::find_last_not_of(char* s1, size_t n, size_t pos = -1){
	MyString ss1;
	ss1.assign(s1, n);
	return find_last_not_of(ss1, pos);
}
size_t MyString::find_last_not_of(char c, size_t pos = -1){
	for (int i = length(); i >=0; i--){
		if (s[i] != c){
			pos = i;
			break;
		}
	}
	return pos;
}
MyString MyString::substr(size_t pos, size_t len){
	MyString x;
	x = assign(pos, len);
	return x;
}
int MyString::compare(MyString s1){
	int l1, l2;
	l1 = length();
	l2 = s1 . length();
	int f = 0;
	int min = (l1 < l2  )? l1:l2;
	for (int i = 0; i < min; i++){
		if (s[i] < s1.getstring()[i]){
			f = -1;
			break;
		}
		if (s[i] > s1.getstring()[i]){
			f = 1;
			break;
		}
	}
	if (l1 < l2) f = 1;
	if (l1>l2) f = -1;
	return f;
}
int MyString::compare(size_t pos, size_t len, MyString s1){
	MyString t;
	t.assign(s1, pos, len);
	return compare(t);
}
int MyString::compare(size_t pos, size_t len, MyString s1, size_t subpos, size_t sublen){
	MyString t1, t2;
	t1.assign(*this,subpos,sublen);
	t2.assign(s1, pos, len);
	return t1.compare(t2);
}
int MyString::compare(char* s1){
	MyString t;
	t = s1;
	return compare(t);
}
int MyString::compare(size_t pos, size_t len, char* s1){
	MyString t;
	t = s1;
	return t.compare(pos, len, *this);
}
int MyString::compare(size_t pos, size_t len, char* s1, size_t n){
	MyString t;
	t.assign(s1, n);
	return t.compare(pos, len, *this);
}
MyString operator+(MyString lhs, MyString rhs){
	MyString t;
	t += lhs;
	t += rhs;
	return t;
}
MyString operator+ (MyString lhs, char* rhs){
	MyString t;
	t += lhs;
	t += rhs;
	return t;
}
MyString operator+ (char* lhs, MyString rhs){
	MyString t;
	t += lhs;
	t += rhs;
	return t;
}
MyString operator+ (MyString lhs, char rhs){
	MyString t;
	t += lhs;
	t += rhs;
	return t;
}
MyString operator+ (char lhs, MyString rhs){
	MyString t;
	t += lhs;
	t += rhs;
	return t;
}
bool operator== (MyString lhs, MyString rhs){
	int n = lhs.compare(rhs);
	return !(n*n);
}
bool operator== (char*   lhs, MyString rhs){
	int n = rhs.compare(lhs);
	return !(n*n);
}
bool operator== (MyString lhs, char*   rhs){
	int n = lhs.compare(rhs);
	return !(n*n);
}
bool operator!= (MyString lhs, MyString rhs){
	return !(lhs == rhs);
}
bool operator!= (char*   lhs, MyString rhs){
	return !(lhs == rhs);
}
bool operator!= (MyString lhs, char*   rhs){
	return !(lhs == rhs);
}
bool operator<  (MyString lhs, MyString rhs){
	int n = lhs.compare(rhs);
	if (n == 1) return 1;
	return 0;
}
bool operator<  (char*   lhs, MyString rhs){
	int n = rhs.compare(lhs);
	if (n == -1) return 1;
	return 0;
}
bool operator<  (MyString lhs, char*   rhs){
	int n = lhs.compare(rhs);
	if (n == 1) return 1;
	return 0;
}
bool operator<= (MyString lhs, MyString rhs){
	return !(lhs>rhs);
}
bool operator<= (char*   lhs, MyString rhs){
	return !(lhs>rhs);
}
bool operator<= (MyString lhs, char*   rhs){
	return !(lhs>rhs);
}
bool operator>  (MyString lhs, MyString rhs){
	int n = lhs.compare(rhs);
	if (n == -1) return 1;
	return 0;
}
bool operator>  (char*   lhs, MyString rhs){
	int n = rhs.compare(lhs);
	if (n == 1) return 1;
	return 0;
}
bool operator>  (MyString lhs, char*   rhs){
	int n = lhs.compare(rhs);
	if (n == -1) return 1;
	return 0;
}
bool operator>= (MyString lhs, MyString rhs){
	return !(lhs < rhs);
}
bool operator>= (char*   lhs, MyString rhs){
	return !(lhs < rhs);
}
bool operator>= (MyString lhs, char*   rhs){
	return !(lhs < rhs);
}
void swap(MyString& x, MyString& y){
	x.swap(y);
}
istream& operator>> (istream& is, MyString& str){
	char s1[1000000];
	cin >> s1;
	str.setstring(s1);
	return is;
}
ostream& operator<< (ostream& os, MyString& str){
	cout << str.getstring() << "\n";
	return os;
}
istream& getline(istream& is, MyString& str, char delim){
	char ch = 0;
	istream& get(char& ch);
	while (is && ch != delim)
	{
		istream& get(char& ch);
		str += ch;
	};
	return is;
}
istream& getline(istream& is, MyString& str);