# qml与C++的通信方式

C++ 和 QML 之间的通信方式主要有以下几种：

### 1. 将 C++ 对象暴露给 QML 上下文



这是最直接、最常用的通信方式。通过 `QQmlContext::setContextProperty()`，你可以将一个 C++ 对象的实例暴露给 QML 的根上下文。这样，QML 就可以像访问普通属性一样，直接访问该 C++ 对象的属性、调用其方法以及连接其信号。

- **特点**:

  - C++ 对象在 QML 中作为 **单例** 使用。
  - 生命周期由 **C++ 端管理**。
  - **适用场景**: 应用程序的核心逻辑、数据管理器或全局服务。
  - **QML 导入**：使用 `setContextProperty` 不需要 import 语句

- 示例：

  ```c++
  int main(int argc, char * argv[]) {
  	//... 前置初始化
      QQmlApplicationEngine engine;
      // 其中的SingletonManager为示例的单例类
      engine.rootContext()->setContextProperty("singleTonManager", SingletonManager::getInstance());
      // 也可以使用指针别名 -- 可选
      engine.rootContext()->setContextProperty("appManager", &SingletonManager::getInstance());
      
      // ... 加载main.qml
      
      
  }
  ```

  ```qml
  // qml中调用
  Window{
  	Component.onCompleted: {
  		console.log("Singleton appName", singletonManager.appName)
  	}
  	Connections {
  		target: singletonManager
  		onAppNameChanged: {
  			console.log("App name changed to: ", singletonManager.appName)
  		}
  		onInitiallized: {
  			console.log("singleton initalized singal received")
  		}
  	}
  	// QQmlContext::setContextProperty() 传入的单例调用
  	Button {
  		singletonManager.login(usernameField.text, passwordField.text)
  	}
  }
  ```



### 2. 注册 C++ 类型到 QML

通过 `qmlRegisterType()`，你可以将一个 C++ 类注册为 QML 中的一个新类型。这样，你就可以在 QML 中像使用 `Button` 或 `Rectangle` 一样，声明式地创建和使用这个 C++ 类的实例。

- **特点**:
  - 在 QML 中可以 **创建多个实例**。
  - 生命周期由 **QML 引擎管理**。
  - **适用场景**: 可复用的 UI 组件、自定义数据模型（如 `QAbstractListModel` 的子类）或任何需要在 QML 中多次实例化的对象。

- 

### 3. 使用模型/视图编程

这是处理大量数据展示的常用方式。你可以创建一个继承自 `QAbstractListModel` 或 `QAbstractTableModel` 的 C++ 类作为数据模型，并通过 `setContextProperty()` 或 `qmlRegisterType()` 将其暴露给 QML。然后，QML 中的 `ListView`、`GridView` 等视图组件可以直接绑定这个模型，从而实现高效的数据展示。

- **特点**:
  - 将 **数据和视图分离**，提高了性能和可维护性。
  - 数据处理和管理在 **C++ 后端** 完成。
  - **适用场景**: 列表、表格或任何需要高效展示大量结构化数据的场景。

### 4. 调用 QML 方法和设置属性

C++ 也可以主动与 QML 通信。你可以通过 `QObject` 提供的机制，在 C++ 端获取 QML 对象的指针，然后调用其 `Q_INVOKABLE` 标记的方法或设置其 `Q_PROPERTY` 标记的属性。

- **特点**:
  - 允许 **C++ 主动控制 QML** 界面。
  - 需要获取 QML 对象的指针，通常通过 `QQmlApplicationEngine::rootObjects()` 或 `QQuickItem::findChild()` 等方法。
  - **适用场景**: C++ 后端需要根据某些事件（如数据更新或网络响应）来更新 QML 界面。

### 5. 使用信号和槽



Qt 的核心机制之一。C++ 对象可以发出信号，QML 端可以通过 `Connections` 元素或 `onSignalName` 属性来连接并处理这些信号。反之亦然，QML 也可以发出信号，由 C++ 的槽函数来处理。

- **特点**:
  - **解耦** 了 C++ 和 QML 之间的依赖。
  - **异步通信** 的良好选择。
  - **适用场景**: 事件驱动的编程，例如 C++ 后台任务完成时通知 QML 更新界面。

------

总的来说，这五种方式各有侧重，但通常在项目中会结合使用。例如，你可能会用 `setContextProperty` 来暴露一个全局的 `Backend` 对象，用 `qmlRegisterType` 来注册一个可复用的 `CustomButton` 组件，并在这两者之间使用信号和槽进行事件通信。