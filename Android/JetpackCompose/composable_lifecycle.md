## composable의 생명주기

reference : https://developer.android.com/jetpack/compose/lifecycle?hl=ko



### 개요

https://developer.android.com/static/images/jetpack/compose/lifecycle-composition.png?hl=ko![image](https://github.com/mettew0585/self_study_log/assets/48712755/b1c0baf6-d4c3-4017-a11f-0e216c8c457f)

- composition :  a tree-structure of the composables that describe your UI.
- composition은 초기 composition을 통해서만 생성되고 recomposition을 통해서만 업데이트 된다.

```kotlin
@Composable
fun MyComposable() {
    Column {
        Text("Hello")
        Text("World")
    }
}
```
https://developer.android.com/static/images/jetpack/compose/lifecycle-hierarchy.png?hl=ko![image](https://github.com/mettew0585/self_study_log/assets/48712755/b6d2cd0a-5857-4bde-9124-a6810e61390e)

- 컴포지션 내 MyComposable의 표현.


### composable in composition

- composition 내의 composable instanc는  call site로 식별된다.
- call site란? 컴포저블이 호출되는 소스 코드 위치
- compose compiler는 각 call site를 고유한 것으로 간주함.
- 
