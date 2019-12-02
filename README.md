# C++ Winrt ProgressRing During long operation

Simple C++ winrt example project made to show that simple setting IsActive="True" in a function does not
automatically update the UI. And to start a discussion on how this can be achieved.  

## Getting Started

Compile the project and click the button. The first 500,000 prime numbers will be calculated. Takes about a minute
on my Intel I7-3770K. You can lower that number if it takes to long


## Xaml Code MainPage.xaml
```
<RelativePanel  HorizontalAlignment="Center" VerticalAlignment="Center">
        <ProgressRing Margin="0,5,20,0" x:Name="pring" IsActive="False" />
        <Button RelativePanel.RightOf="pring" x:Name="myButton" Click="ClickHandler">Click Me</Button>
    </RelativePanel>
```

## cpp code MainPage.cpp

```
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
```
