### Static Keyword and Uses
1. All the variables, declared with static keyword are not instance member variable. These variables are declared only once for the class whereas all the other instance variables are declared everytime for each new object.
2. Default value of static variables is 0
3. We can also declare a static member function. A static member function only access static variables only. It can't access instance member variables and function because a static member function can be called without even creating the object, so how can we access instance variables or instance function if we haven't created any instance. Instance basically means object.
4. We can't declare a static local variable inside any function, we can only create a static variable in the class.
5. We can create a static inner class.

```
class Example {
  int x;
  static int y;

  public void fun1() {
    // instance function
  }

  public static void fun2() {
    // static funtion

    y = 10; // allowed
    x = 10; // not allowed
  }

  // static inner class
  static class Test {
      public static String country = "INDIA";
  }
}

class Solution {
  public static void main(Strings[] args) {
    Example.y = 10;
    Example.fun2();

    Example e1 = new Example();
    e1.fun1();

    // accessing static inner class
    String ans = Example.Test.country;
    System.out.println(ans);
  }
}
```

### Wrapper Classes
- A pure Object Oriented Programming says that every variable in our program should be an object or should represent a real world entity. But if we look closly then we can say that JAVA is not purely OOP language because we can declare some variables by using primitive data types which are not classes hence those variables are not objects.

```
int x = 5;
char ch = '5';
```
These variables are declared using primitive data type, hence are not objects. To solve this problem JAVA has the concept of Wrapper classes where a class only has one primitive datatype so rather than directly creating a variable using primitive data type we can make use of these wrapper classes.
As said, these class has only one variable in it. 
Eg: 
```
// the below is just an example, these classes are already available in JAVA
class Integer {
  private int x;

  // all public member functions like
  getValue() {...}
  setValue() {...}
  and so on.
}


Integer x = 10;

// Some useful functions
Integer.valueOf(input, base); 
  input => string, returs => object referenes, base => base of the number. default is 10.

Integer.parseInt()

x.intValue();
```

Data Type           Wrapper Class
boolean             Boolean
int                 Integer
char                Character
byte                Byte


### Command Line Arguments
```
/* Prg to print the sum of all the nums passed in command line argument */

public class Example {
  public static void main(String[] args) {
    int sum = 0;
    for(int i=0; i<args.length; i++) {
      sum += Integer.parseInt(args[i]);
    }

    System.out.println(sum);
  }
}
```

### Packages
- Packages are nothing but a way to organize our java programs. We keep all groups of classes working on a similar problem or topic in one package and similar group all set of classes in different packages.
eg: package => java.io => have all classes for input / output

Advantages
1. Help in avoid name collision, we can have same class name in different packages.
2. Good practice for project and code maintanance.

```
package world;

public class Hello {
  public static void main(String[] args) {
    System.out.println("Hello World");
  }
}

compile => javac -d . Hello.java
run => world.Hello
```


### Access Modifier
There are 4 types
1. public => accessible by all classes of all package
2. private => accessible only within the class body
3. protected => accessible only by class of same package and child class of other package
4. default => accessible by classes in the same package

- Outer class can use => public, default
- Inner class can use => all four
- In one java file there should be at most one public class, which will be the outer class. 

### Inheritance
1. private members of superClass (base class) are not accessible by sub class (derived class).
2. variables declared using default accessibility in base class are not accessible by derived classes of other packages.