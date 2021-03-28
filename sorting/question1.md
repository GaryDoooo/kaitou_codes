Hello, I have a question on binary search. In the book CPH from Lasksenon, an example code is
```
int k = 0;
for (int b = n/2; b >= 1; b /= 2) 
{
	while (k+b < n && array[k+b] <= x) k += b;
}
if (array[k] == x) {// x found at index k}
```
I wonder why is a while loop is used here. If the while loop can be replaced with a if statement like below? I tested with some data, if statement seems to work. But may I miss something?
```
if (array[k+b]<=x) k+=b;
```
Please advise. Thanks a lot. 

