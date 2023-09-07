
## 문(statement)과 식(expression)의 구분
코틀린에서 if는 식이지 문이 아님. 
- 식 : 값을 만들어 내며 다른 식의 하위 요소로 계산에 참여할 수 있음
- 문 : 자신을 둘러싸고 잇는 가장 안쪽 블록의 최상위 요소로 존재하며 아무런 값을 만들어내지 못함
자바에서는 모든 제어구조가 문인 반면 코틀린에서는 루프를 제외한 대부분의 제어구조가 식이다.

예)

```kotlin
fun max(a:Int,b:Int):Int=if(a>b) a else b
```

타입추론 : 컴파일러가 타입을 분석해 타입을 정해주는 기능 
```kotlin
fun max(a:Int,b:Int) = if(a>b) a else b
```


## 변수선언

초기화 식을 사용하지 않고 변수를 선언하려면 변수 타입을 반드시 명시해야 한다.
```kotlin
val answer:Int
answer=42
```

val변수는 블록을 실행할 때 정확히 한번만 초기화 되어야 함.
val참조 자체는 불변일지라도 그 참조가 가리키는 객체의 내부 값은 변경될 수 있다.

```kotlin
val languages=arrayListOf("Java")
languages.add("Kotlin")
```

## 클래스와 프로퍼티

```java
public class Person{
  private final String name;

  public Person(String naem){
    this.name=name;
  }

  public String getName(){
    return name;
  }
}
```
-> kotlin으로 변환할 경우

```kotlin
class Person(val name : String)
```

프로퍼티 
- 코틀린 프로퍼티는 자바의 필드와 접근자 메소드(getter,setter)를 완전히 대신한다

```kotlin
class Person(
  val name : String,  // 읽기 전용 프로퍼티, 코틀린은 (비공개)필드와 getter를 만들어낸다.
  var isMarried : Boolean  // (비공개) 필드, getter,setter를 만들어낸다.
)
```

사용하기
```kotlin
val person=Person("Bob",true)
println(person.name)
println(person.isMarried)
```

커스텀 접근자

```kotlin

class Rectangle(val height:Int, val width: Int){
  val isSquare:Boolean
      get(){
        return height==width
      }
}


val rectangle = Rectangle(41,43)
println(rectangle.isSquare)
```

파라미터가 없는 함수를 정의 하는 방식 vs 커스텀 게터를 정의하는 방식
- 두 방식 모두 비슷함. 구현이나 성능상 차이는 없음
- 차이가 나는 부분은 가독성


## 선택 표현과 처리 : enum과 when

```kotlin

enum class Color{
  RED,ORANGE,YELLOW,GREEN,BLUE,INDIGO,VIOLET
}

```

```kotlin

enum class Color(
  val r : Int, val g : Int, val b : Int // 상수의 프로퍼티를 정의한다
){
  RED(255,0,0),ORANGE(255,165,0),  // 각 상수를 생성할 때 그에 대한 프로퍼티 값을 지정한다
  YELLOW(255,255,0),GREEN(0,255,0),BLUE(0,0,255),
  INDIGO(75,0,130);

  fun rgb()=(r*256+g)*256 +b
}

```



## 스마트캐스트 

```kotlin
interface Expr

class Num(val value : Int) : Expr
class Sum(val left : Expr,val right: Expr) : Expr


fun eval ( e: Expr ) : Int{
  if ( e is Num) {
    val n = e as Num // 여기서 Num으로 타입을 변환하는데 이것은 불필요한 중복임
    return n.value
  }
  if ( e is Sum){
    return eval(e.right)+eval(e.left)// 변수 e 대해 스마트 캐스트를 사용함
  }
  throw IllegalArgumentException("Unknown Expression")
}
```

자바에서 어떤 변수의 타입을 instanceof로 확인한 다음에 그 타입에 속한 멤버에 접근하기 위해서는 명시적으로 변수 타입을 캐스팅해야 함.
*코틀린에서는 컴파일러가 캐스팅을 대신 해줌.*






