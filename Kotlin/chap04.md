# 클래스, 객체, 인터페이스


## 코틀린 인터페이스

```kotlin
interface Clickable{
  fun click()
}

///Clickable 인터페이스에 대한 구현

class Buttion : Clickable {
  override fun click() = println("I was clicked")
}
```
- 코틀린 인터페이스 안에는 추상 메소드 뿐 아니라 구현이 있는 메소드도 정의할 수 있음 . (자바 8 의 디폴트 메소드와 비슷함)
- 다만 인터페이스에는 아무런 상태(필드)도 들어갈 수 없음


```kotlin
interface Clickable{
  fun click() //일반 메소드
  fun showOff()=println("I'm clickable") // 디폴트 구현이 있는 메소드
}
```

## open, final, abstract 변경자 : 기본적으로 final 

- 코틀린의 클래스와 메소드는 *기본적으로 final*
- 어떤 클래스의 상속을 허용하려면 클래스 앞에 open 변경자를 붙여야 한다. 오버라이드를 허용하고 싶은 메소드나 프로퍼티 앞에도 open 변경자를 붙여야 한다.

```kotlin
open class RichButton : Clickalbe {
  fun disable() {}   // 이 함수는 파이널이다. 하위 클래스가 이 메소드를 오버라이드할 수 없다.
  open fun animate() {} // 이 함수는 열려있다. 하위 클래스에서 이 메소드를 오버라이드해도 된다.
  override fun click() {} /// 이 함수는 상위 클래스에서 선언된 열려있는 메소드를 오버라이드 한다. *오버라이드한 메소드는 기본적으로 열려있다.*

}
```

코틀린에서의 추상클래스

```kotlin
abstract class Animated{

  abstract fun animate()
  open fun stopAnimating(){
  }
  fun animateTwice(){
  }
  // 추상 클래스에 속했더라도 비추상 함수는 기본적으로 파이널이지만 원한다면 open으로 허용할 수 있다.
}
```



## 가시성 변경자

| 변경자 | 클래스 멤버 | 최상위 선언 |
|---|---|---|
| public | 모든 곳에서 볼 수 있다. | 모든 곳에서 볼 수 있다.|
| internal | 같은 모듈 안에서만 볼 수 있다. | 같은 모듈 안에서만 볼 수 있다.|
| protected | 하위 클래스 안에서만 볼 수 있다 | 최상위 선언에 적용할 수 없음 |
| private | 같은 클래스 안에서만 볼 수 있다. | 같은 파일 안에서만 볼 수 있다 |



```kotlin
internal open class TalkativeButton : Focusable{
  private fun yell() = println("Hey!")
  protected fun whisper() = println("Let's talk")
}

fun TalkativeButton.giveSpeech() { // 오류, public 멤버가 internal 수신 타입인 'TalkativeButton을 호출함'
  yell()  // yell을 접근할 수 없음. yell은 TalkativeButton의 private 멤버임
  whisper() // whisper에 접근할 수 없음. whisper는 TalkativeButton의 protected 멤버임.
}
```

코틀린은 public함수인 giveSpeech 안에서 그보다 가시성이 더 낮은 타입인 TalkativeButton을 참조하지 못하게 한다. 

이런 규칙은 어떤 함수를 호출하거나 어떤 클래스를 확장할 때 필요한 모든 타입에 접근할 수 있게 보장해준다.

## 클래스 위임


- 상속을 허용하지 않는 클래스에 새로운 동작을 추가해야 될 때가 잇음
- 이럴때 사용하는 일반적인 방법이 데코레이터 패턴
  - 데코레이터 패턴 : 상속을 허용하지 않는 클래스(기존 클래스) 대신 사용할 수 있는 새로운 클래스(데코레이터)를 만들되 기존 클래스와 같은 인터페이스를 데코레이터가 제공하게 만들고, 기존 클래스를 데코레이터 내부에 필드로 유지하는 것. 이때 새로 정의 해야 되는 기능은 데코레이터의 메소드에 새로 정의하고 기존 기능이 그대로 필요한 부분은 데코레이터의 메소드가 기존 클래스의 메소드에게 요청을 전달한다.
  - 데코레이터 패턴의 단점 : 준비코드가 상당히 많이 필요하다. Collection 같이 단순한 인터페이스를 구현하면서 아무 동작도 변경하지 않는 데코레이터를 만들 때 조차도 다음과 같이 복잡한 코드를 작성해야 함.
  
```kotlin

class DelegatingCollection<T> : Collection<T> {
  private val innerList = arrayListOf<T>()

  override val size : Int get() = innerList.size
  override fun isEmpty() : Boolean = innerList.isEmpty()
  override fun contains(elements : T) : Boolean = innerList.contains(element)
  override fun iterator() : Iterator<T> = innerList.iterator()
  override fun containsAll(elements : Collection<T>) : Boolean =
    innerList.containsAll(elements)
}
```

=> 인터페이스를 구현할 때 by 키워드를 통해 그 인터페이스에 대한 구현을 다른 객체에 위임 중이라는 사실을 명시할 수 있다. 

```kotlin
class DelegatingCollection<T> (
  innerList : Collection<T> = ArrayList<T> ()
) : Collection<T> by innerList  {}
```

