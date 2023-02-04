#include <iostream>


template<typename T>
void display(size_t length, T array[])
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


template<typename T>
T max(size_t length, T array[])
{
	T max = array[0];

	for (size_t i = 0; i < length; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}

	return max;
}


template<typename T>
T min(size_t length, T array[])
{
	T min = array[0];

	for (size_t i = 0; i < length; ++i)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}

	return min;
}


template<typename T>
void sort(size_t length, T array[])
{
	T temp = 0;

	for (size_t i = 0; i < length - 1; ++i)
	{
		for (size_t j = 0; j < length - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}


template<typename T>
void edit(size_t length, T array[], size_t index, T symbol)
{
	if (index <= length)
	{
		array[index] = symbol;
	}
}


template<typename T>
T binfind(size_t length, T array[], T symbol)
{
	sort(length, array);

	size_t begin = 0;
	size_t end = length;

	size_t index = 0;

	while (begin <= end)
	{
		index = (begin + end) / 2;

		if (symbol < array[index])
		{
			end = index - 1;
		}

		if (symbol > array[index])
		{
			begin = index + 1;
		}

		if (symbol == array[index])
		{
			return index;
		}
	}

	return -1;
}






int main()
{
	setlocale(LC_ALL, "rus");


	int integer_array[6]{ 101, 0, 15, 74, 444, 19 };
	char char_array[7]{ 'a', 'B', '?', '2', 'D', 'z', '.'};

// ФУНКЦИЯ DISPLAY()
	std::cout << "ФУНКЦИЯ DISPLAY(): " << std::endl;

	std::cout << "Массив integer_array: "; display(6, integer_array);
	std::cout << "Массив char_array: "; display(7, char_array); std::cout << std::endl;


// ФУНКЦИЯ MAX()
	std::cout << "ФУНКЦИЯ MAX(): " << std::endl;

	std::cout << "Наибольший символ из массива integer_array: " << max(6, integer_array) << std::endl;
	std::cout << "Наибольший символ из массива char_array: " << max(7, char_array) << std::endl << std::endl;


// ФУНКЦИЯ MIN()
	std::cout << "ФУНКЦИЯ MIN(): " << std::endl;

	std::cout << "Наименьший символ из массива integer_array: " << min(6, integer_array) << std::endl;
	std::cout << "Наименьший символ из массива char_array: " << min(7, char_array) << std::endl << std::endl;


// ФУНКЦИЯ SORT()
	std::cout << "ФУНКЦИЯ SORT(): " << std::endl;

	sort(6, integer_array);
	sort(7, char_array);

	std::cout << "Массив integer_array после сортировки: "; display(6, integer_array);
	std::cout << "Массив char_array после сортировки: "; display(7, char_array); std::cout << std::endl;


// ФУНКЦИЯ EDIT()
	std::cout << "ФУНКЦИЯ EDIT(): " << std::endl;

	edit(6, integer_array, 2, 777);
	edit(7, char_array, 0, '#');

	std::cout << "Массив integer_array после [2] = 777: "; display(6, integer_array);
	std::cout << "Массив char_array после [0] = '#': "; display(7, char_array);

	edit(6, integer_array, 999, 1);
	std::cout << "Массив integer_array после [999] = 1: "; display(6, integer_array); std::cout << std::endl << std::endl;


// ФУНКЦИЯ BINFIND()
	std::cout << "ФУНКЦИЯ BINFIND(): " << std::endl;

	sort(6, integer_array);
	std::cout << "Массив integer_array после сортировки: "; display(6, integer_array);

	std::cout << "Индекс искомого числа 15: " << binfind(6, integer_array, 15) << std::endl;
	std::cout << "Индекс искомого числа 444: " << binfind(6, integer_array, 444) << std::endl;
	std::cout << "Индекс искомого числа 777: " << binfind(6, integer_array, 777) << std::endl;
	std::cout << "Индекс искомого числа 101: " << binfind(6, integer_array, 101) << std::endl;
	std::cout << "Индекс искомого числа 74: " << binfind(6, integer_array, 74) << std::endl;
	std::cout << "Индекс искомого числа 0: " << binfind(6, integer_array, 0) << std::endl;
	std::cout << "Индекс искомого числа 19: " << binfind(6, integer_array, 19) << std::endl << std::endl << std::endl;;


//


	int integer_array_2[14] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	sort(14, integer_array_2);
	std::cout << "Массив integer_array после сортировки: "; display(14, integer_array_2);

	std::cout << "Индекс искомого числа 8: " << binfind(14, integer_array_2, 8) << std::endl;
	std::cout << "Индекс искомого числа 9: " << binfind(14, integer_array_2, 9) << std::endl;
	std::cout << "Индекс искомого числа 1: " << binfind(14, integer_array_2, 1) << std::endl;
	std::cout << "Индекс искомого числа 13: " << binfind(14, integer_array_2, 13) << std::endl;
	std::cout << "Индекс искомого числа 14: " << binfind(14, integer_array_2, 14) << std::endl;
	std::cout << "Индекс искомого числа 5: " << binfind(14, integer_array_2, 5) << std::endl;
	std::cout << "Индекс искомого числа 2: " << binfind(14, integer_array_2, 2) << std::endl;
	std::cout << "Индекс искомого числа 12: " << binfind(14, integer_array_2, 12) << std::endl;
	std::cout << "Индекс искомого числа 3: " << binfind(14, integer_array_2, 3) << std::endl;
	std::cout << "Индекс искомого числа 333333: " << binfind(14, integer_array_2, 333333) << std::endl;
	std::cout << "Индекс искомого числа 11: " << binfind(14, integer_array_2, 11) << std::endl;
	std::cout << "Индекс искомого числа 4: " << binfind(14, integer_array_2, 4) << std::endl;
	std::cout << "Индекс искомого числа 7: " << binfind(14, integer_array_2, 7) << std::endl;
	std::cout << "Индекс искомого числа 6: " << binfind(14, integer_array_2, 6) << std::endl;
	std::cout << "Индекс искомого числа 10: " << binfind(14, integer_array_2, 10) << std::endl << std::endl << std::endl;;


//


	int integer_array_3[14] { 5, 202, 77, 4, 11, 2114, 765, 0, 54, 90, 356, 1, 8, 3134 };
	sort(14, integer_array_3);
	std::cout << "Массив integer_array после сортировки: "; display(14, integer_array_3);

	std::cout << "Индекс искомого числа 2114: " << binfind(14, integer_array_3, 2114) << std::endl;
	std::cout << "Индекс искомого числа 8: " << binfind(14, integer_array_3, 8) << std::endl;
	std::cout << "Индекс искомого числа 1: " << binfind(14, integer_array_3, 1) << std::endl;
	std::cout << "Индекс искомого числа 3134: " << binfind(14, integer_array_3, 3134) << std::endl;
	std::cout << "Индекс искомого числа 202: " << binfind(14, integer_array_3, 202) << std::endl;
	std::cout << "Индекс искомого числа 98537503: " << binfind(14, integer_array_2, 98537503) << std::endl;
	std::cout << "Индекс искомого числа 77: " << binfind(14, integer_array_3, 77) << std::endl;
	std::cout << "Индекс искомого числа 5: " << binfind(14, integer_array_3, 5) << std::endl;
	std::cout << "Индекс искомого числа 0: " << binfind(14, integer_array_3, 0) << std::endl;
	std::cout << "Индекс искомого числа 765: " << binfind(14, integer_array_3, 765) << std::endl;
	std::cout << "Индекс искомого числа 54: " << binfind(14, integer_array_3, 54) << std::endl;
	std::cout << "Индекс искомого числа 356: " << binfind(14, integer_array_3, 356) << std::endl;
	std::cout << "Индекс искомого числа 11: " << binfind(14, integer_array_3, 11) << std::endl;
	std::cout << "Индекс искомого числа 90: " << binfind(14, integer_array_3, 90) << std::endl;
	std::cout << "Индекс искомого числа 4: " << binfind(14, integer_array_3, 4) << std::endl;




	return 0;
}
