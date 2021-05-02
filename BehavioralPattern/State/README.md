# State Pattern
![state](StatePattern.jpg)

- 객체가 특정 상태에 따라 행위를 달리하는 상황에서 객체 자신이 직접 상태를 체크하여 상태에 따라 행위를 호출하지 않고 **상태를 객체화**하여 상태에 맞는 행동을 할 수 있도록 위임하는 패턴이다.

## 관련 용어
### state
- 상태를 나타내는 **인터페이스**이다.
- 이 인터페이스를 실체화한 상태 클래스로 기존 상태 클래스를 대신하여 사용할 수 있다.

### ConcreteState
- `Context` 객체가 요청한 작업을 자신의 상태에 맞게 구현된 방식대로 실행한다.
- 일반적으로 다음 상태를 결정해 상태 변경을 `Context` 객체에 요청하는 역할도 수행한다.
- 객체가 시스템에 존재하는 동안 객체가 가질 수 있는 어떤 조건이나 상황을 의미한다.

### Context
- **상태를 이용하는 역할**을 수행한다.
- 상태를 나타내는 상태 변수와 실제 시스템의 상태를 구성하는 여러 가지 변수가 있다.
- 각 상태 클래스에서 상태 변경을 요청해 상태를 바꿀 수 있도록 하는 함수가 제공된다.
- `request` 함수는 실제 행위를 실행하는 대신 해당 상태 객체에 **행위 실행을 위임**한다.

## 특징
- 객체의 내부 상태에 따라 스스로 행동을 변경할 수 있도록 한다.
- 상태에 맞는 행동들이 상태 클래스로 분리되므로 구조화된 형태로서 각 상태들을 관리할 수 있다.
- 대량의 조건문/switch 문을 회피할 수 있다.
  - 코드가 간결해지고 가독성이 올라간다.
- 상태 패턴도 관련 클래스가 많아지면 복잡도가 증가한다.
- 전략 패턴과 유사한 점이 많다.
  - 차이점은 전략 패턴은 상속을 대체하려는 목적으로, 상태 패턴은 조건문을 대체하려는목적으로 사용된다.

## 예제
- [State](/BehavioralPattern/state/state.cpp)