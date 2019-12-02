#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::loadingtest::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }



	bool isPrime(int n)
	{
		// Corner case 
		if (n <= 1)
			return false;

		// Check from 2 to n-1 
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return false;

		return true;
	}
	// Function to iterate through primes
	void loopPrime(int n)
	{
		for (int i = 2; i <= n; i++) {
			if (isPrime(i))
				int empty = 10;//Just intialize random variable. We are just taking up time here
		}
	}



    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
		pring().IsActive(true);// Set loading to true
		pring().UpdateLayout();
        myButton().Content(box_value(L"Clicked"));
		
		loopPrime(500000); //Long running operation here
		pring().IsActive(false);// Set to false when done
    }

}
