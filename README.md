# mind-enlightened

The goal of this project was to use a data set (student-mat csv) which has numerous variables that can be used to predict the students final grade.
So why did I decide to solve this problem with three separate ways? I just thought it would be interesting. I find it to be valuable to actually know what is going on when solving a problem.
Abstraction is good, however I am not someone who can learn by just importing some library and googling exactly what to do.
When I was browsing youtube one day I saw a video about machine learning projects so I watched it and saw sklearn being used for this very data set. This was right after I finished my linear algebra class, and I knew how to use OLS to solve this exact problem, so that is what I did.

1) I used sklearn and just copied what I saw in the video while googling some stuff. This solution worked and was rather quick, but I had absolutely no clue what was happening. I didn't necessarily feel like I learned anything of value. This is the closest thing to the "black box" solution, where you just put in an input to a black box and get an output.

2) With this I had implemented my Ordinary Least Squares solution using numpy. While there is still some abstracted, there is a very clear solution to how this works. Each variable that was selected could be considered its own point somewhere in space. I will only use 2d depictions in my examples, as my actual solution focuses on things above the third dimension. 
![image](https://github.com/user-attachments/assets/5e0133cd-be7d-4221-8544-6bc173c23ea1)
If there are a bunch of points, we must create a line that minimizes the "error" which is the y value here (this is because x is the independent values which are just the supporting variables)
The equation that is used is ∑(real y - predicted y)^2, and this is called the cost function
The fact it is squared is rather important. We don't want to have even and negative numbers cancel each other out in the summation, so we square it to make everything positive. This clarification actually helps a lot with the mathematical understanding.
If we were to take the derivative and find the minimum, this would just be at the bottom of a parabola. 
![image](https://github.com/user-attachments/assets/0bfe9548-a657-42a8-9d7a-945c6dfa03f4)
If you were to take the derivative of the cost function, you would be able to "minimize" it aka finding the smallest number which would give us the best fit line, and this is exactly what OLS is. 
![image](https://github.com/user-attachments/assets/273ec3d9-43c9-44ad-9150-1775dbebbd6a)
![image](https://github.com/user-attachments/assets/706206b3-6689-4466-aafe-f2d721275213)
With this you can find an easy formula that can calculate the best fit line with matrices.

3) My solution for gradient descent used the exact same concept of OLS except for the fact it was iterative. Gradient descent starts at a random point on the aformentioned "parabola" and calculating the gradient is like calculating the slope, so it gives an estimate and how far to go down for the next iteration. It repeats this process until it is at the very bottom. This calculation is slower for a smaller data set, however the iterative approach is better for very large data sets when an exact matrix calculation will grow exponentially in time.
![image](https://github.com/user-attachments/assets/d77530a0-bda5-46c7-9e3c-563e939e60e0)

To conclude this, we must compare my created solutions to the library solution. Was my OLS solution faster? Yes by a few milliseconds. Was my gradient descent solution faster? Not even close. Were both my solutions more lines of code and more complex? Yes. But at least I learned something and created something using my own knowledge and experience. The moral to the story is that when solving a problem the fastest solution isn't always the most valuable depending on how you look at it. Sure I would definitely use a near-infallible library if I had a time restraint on making something or I was doing it for money, but I can argue it helps more in the future to actually do things yourself the hard way.






