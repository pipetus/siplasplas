int main()
{
   int i, j, *p;

   // Correct usage: the variable i is an lvalue.
   i = 7;

   // Incorrect usage: The left operand must be an lvalue.
   7 = i;
   j * 4 = 7;

   // Correct usage: the dereferenced pointer is an lvalue.
   *p = i;

   const int ci = 7;
   // Incorrect usage: the variable is a non-modifiable lvalue.
   ci = 9;

   // Correct usage: the conditional operator returns an lvalue.
   ((i < 3) ? i : j) = 7;
}
