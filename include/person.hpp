const size_t n_literals = 27;
size_t letterI(const char letter, const bool is_capital) {
	int first_letter_code = static_cast<int>(is_capital ? 'A' : 'a');
	size_t result = static_cast<int>(letter) - first_letter_code + 1;
	return result;
}
struct person {
	char * str;
	/*std::string surname;
	std::string name;
	std::string year;*/
	unsigned char name_i;
	unsigned char name_length;
	size_t i(size_t sort_i) const {
		if (sort_i < name_length) {
			return letterI(str[name_i + sort_i], sort_i == 0);
		}
		else {
			return 0;
		}
	}
	char * getName() {
		char * temp = new char[name_length + 1];
		strncpy(temp, &(str[name_i]), name_length);
		temp[name_length] = '\0';
		return temp;
	} //Boost
	~person() {
		delete[] str;
	}
};
std::ostream & operator<<(std::ostream & output, person const & _person)
{
	output << _person.str << " ";
	/*output << _person.name << " ";
	output << _person.year;*/
	return output;
}
std::istream & operator>>(std::istream & input, person & _person)
{
	input >> _person.str;
	/*input >> _person.name;
	input >> _person.year;*/
	return input;
}