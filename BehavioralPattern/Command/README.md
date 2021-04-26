# Command Pattern
![command](CommandPattern.jpg)

## 목적
- 실행될 기능을 캡슐화함으로써 주어진 여러 기능을 실행할 수 있는 재사용성이 높은 클래스를 설계하는 패턴
- 이벤트가 발생했을 때 실행될 기능이 다양하면서도 변경이 필요한 경우 이벤트를 발생시키는 클래스를 변경하지 않고 재사용하고자 할 때 유용하다.
- 실행될 기능을 캡슐화함으로써 기능의 실행을 요구하는 호출자 클래스와 실제 기능을 실행하는 수신자 클래스 사이의 **의존성을 제거**한다.
- 실행될 기능의 변경에도 호출자 클래스를 수정 없이 그대로 사용 할 수 있도록 해준다.

## 관련 용어
### Command
- 실행될 기능에 대한 인터페이스
- 실행될 기능을 `Execute` 함수로 선언한다.

### ConcreteCommand
- 실제로 실행되는 기능을 구현하는 클래스
- Command를 상속받아 구현한다.

### Invoker
- 기능의 실행을 요청하는 호출자 클래스

### Receiver
- ConcreteCommand의 기능을 실행하기 위해 사용하는 수신자 클래스

## 예제
- [Command Pattern](/BehavioralPattern/Command/command.cpp)