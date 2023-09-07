
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
