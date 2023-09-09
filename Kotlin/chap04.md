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



