## composable의 생명주기

reference : https://developer.android.com/jetpack/compose/lifecycle?hl=ko



### 개요
![image](https://github.com/mettew0585/self_study_log/assets/48712755/6cc2cc73-5df9-4f58-9463-e0e2e4110ba2)


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

![image](https://github.com/mettew0585/self_study_log/assets/48712755/5e67f560-e613-49fc-b08f-6393671fa8d8)

- 컴포지션 내 MyComposable의 표현.


### composable in composition

- composition 내의 composable instanc는  call site로 식별된다.
- call site란? 컴포저블이 호출되는 소스 코드 위치
- compose compiler는 각 call site를 고유한 것으로 간주함.
- 
