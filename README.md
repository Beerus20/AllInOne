# One - Documentation Complète du Projet

## 📋 Vue d'ensemble

**One** est un moteur de rendu graphique extensible et multi-backend développé en C++. Le projet permet de créer des applications graphiques avec un système de plugins, supportant plusieurs backends de rendu (SDL, OpenGL, MinilibX, Vulkan).

### Objectifs principaux
- Créer une abstraction unifiée pour différents backends graphiques
- Fournir un système de plugins dynamiques pour étendre les fonctionnalités
- Offrir une interface utilisateur flexible et personnalisable
- Développer un projet open-source bien documenté et accessible

---

## 🏗️ Architecture Générale

### Structure en couches

```
┌─────────────────────────────────────────┐
│         Plugins (Extensions)            │
│  Video Player, Image Viewer, Terminal   │
└─────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────┐
│          UI System + Widgets            │
│     Windows, Buttons, TextBox, etc.     │
└─────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────┐
│         Plugin System Manager           │
│    Chargement dynamique (.so/.dll)      │
└─────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────┐
│         Application Core                │
│  Orchestration, Event Loop, Resources   │
└─────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────┐
│      Rendering Abstraction Layer        │
│            IRenderer Interface          │
└─────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────┐
│         Backend Implementations         │
│   SDL | OpenGL | MinilibX | Vulkan      │
└─────────────────────────────────────────┘
```

---

## 🎨 Composants Principaux

### 1. Core Engine - Abstraction du Rendu

**IRenderer** est l'interface de base qui définit toutes les opérations de rendu :

```cpp
class IRenderer {
public:
    virtual bool init(int width, int height) = 0;
    virtual void shutdown() = 0;
    virtual void clear(Color color) = 0;
    virtual void present() = 0;
    virtual void drawPixel(int x, int y, Color color) = 0;
    virtual void drawLine(int x1, int y1, int x2, int y2, Color color) = 0;
    virtual void drawRect(Rect rect, Color color, bool filled) = 0;
    virtual void drawTexture(Texture* texture, Vec2 pos) = 0;
    virtual Vec2 getSize() = 0;
};
```

**Backends disponibles :**
- **SDLRenderer** : Backend simple et portable, idéal pour débuter
- **OpenGLRenderer** : Performance élevée, shaders personnalisables
- **MinilibXRenderer** : Pour les projets 42, compatible École 42
- **VulkanRenderer** : API moderne, contrôle bas niveau (futur)

---

### 2. Plugin System

Le système de plugins permet d'étendre One sans modifier le core.

**Architecture des plugins :**

```cpp
class IPlugin {
public:
    virtual bool onInit(PluginContext* context) = 0;
    virtual void onShutdown() = 0;
    virtual void onUpdate(float deltaTime) = 0;
    virtual void onRender(IRenderer* renderer) = 0;
    virtual bool onEvent(Event& event) = 0;
    virtual string getName() = 0;
    virtual string getVersion() = 0;
    virtual bool isEnabled() = 0;
};
```

**Exemples de plugins :**
- **VideoPlayerPlugin** : Lecture de vidéos (FFmpeg)
- **ImageViewerPlugin** : Visualisation d'images avec zoom/pan
- **TerminalPlugin** : Émulateur de terminal intégré
- **TextEditorPlugin** : Éditeur de texte avec coloration syntaxique
- **AudioPlayerPlugin** : Lecteur audio

**Chargement dynamique :**
Les plugins sont compilés en bibliothèques partagées (.so sur Linux, .dll sur Windows) et chargés au runtime via `dlopen()`/`LoadLibrary()`.

---

### 3. UI System

Système d'interface utilisateur basé sur des widgets composables.

**Hiérarchie des widgets :**
```
IWidget (interface)
├── Window
├── Button
├── TextBox
├── Label
├── Slider
├── CheckBox
├── Panel
└── ScrollBar
```

**Fonctionnalités :**
- Système d'événements (clic, hover, focus)
- Layouts flexibles
- Thèmes personnalisables
- Gestion du focus et de la navigation au clavier

---

### 4. Application Core

La classe **Application** (Singleton) orchestre tous les composants :

```cpp
class Application {
private:
    static Application* instance;
    IRenderer* renderer;
    PluginManager* pluginManager;
    UISystem* uiSystem;
    ResourceManager* resourceManager;
    EventManager* eventManager;
    bool isRunning;
    
public:
    static Application* getInstance();
    bool init(Config config);
    void run();
    void shutdown();
};
```

**Boucle principale :**
```cpp
void Application::run() {
    while (isRunning) {
        // 1. Traiter les événements
        renderer->pollEvents();
        eventManager->processEvents();
        
        // 2. Mettre à jour
        float deltaTime = calculateDeltaTime();
        pluginManager->updateAll(deltaTime);
        uiSystem->update(deltaTime);
        
        // 3. Rendu
        renderer->clear(Color::BLACK);
        uiSystem->render(renderer);
        pluginManager->renderAll(renderer);
        renderer->present();
        
        // 4. Limiter FPS
        limitFrameRate();
    }
}
```

---

### 5. Resource Manager

Gestion centralisée des ressources (Singleton) :

```cpp
class ResourceManager {
private:
    map<string, Texture*> textures;
    map<string, Font*> fonts;
    map<string, Sound*> sounds;
    map<string, Shader*> shaders;
    
public:
    Texture* loadTexture(string path);
    Font* loadFont(string path, int size);
    Sound* loadSound(string path);
    void unloadAll();
};
```

**Avantages :**
- Évite les duplications en mémoire
- Cache automatique
- Gestion du cycle de vie centralisée
- Support de multiples formats

---

### 6. Event System

Système d'événements basé sur le pattern Observer :

```cpp
class EventManager {
private:
    queue<Event> eventQueue;
    map<EventType, vector<IListener*>> listeners;
    
public:
    void pushEvent(Event event);
    void subscribe(EventType type, IListener* listener);
    void processEvents();
};
```

**Types d'événements :**
- **Fenêtre** : WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS
- **Clavier** : KEY_PRESSED, KEY_RELEASED, KEY_REPEAT
- **Souris** : MOUSE_MOVED, MOUSE_CLICKED, MOUSE_WHEEL
- **Système** : PLUGIN_LOADED, RESOURCE_LOADED

---

## 🔧 Technologies et Dépendances

### Langages et Standards
- **C++17** ou supérieur
- **CMake 3.15+** pour le build system

### Bibliothèques externes

#### Backends de rendu
- **SDL2** (Simple DirectMedia Layer)
- **OpenGL 3.3+** avec GLEW
- **MinilibX** (École 42)
- **Vulkan SDK** (optionnel, futur)

#### Plugins
- **FFmpeg** pour VideoPlayerPlugin
- **stb_image** pour chargement d'images
- **FreeType** pour le rendu de texte
- **PortAudio** pour l'audio

#### Utilitaires
- **nlohmann/json** pour la configuration
- **spdlog** pour le logging (alternative au Logger custom)

---

## 📂 Structure du Projet

```
One/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── docs/
│   ├── architecture.md
│   ├── plugin-development.md
│   └── api-reference.md
│
├── include/
│   ├── core/
│   │   ├── IRenderer.hpp
│   │   ├── Application.hpp
│   │   └── Config.hpp
│   ├── plugins/
│   │   ├── IPlugin.hpp
│   │   ├── PluginManager.hpp
│   │   └── PluginContext.hpp
│   ├── ui/
│   │   ├── IWidget.hpp
│   │   ├── UISystem.hpp
│   │   ├── Window.hpp
│   │   └── Button.hpp
│   ├── events/
│   │   ├── Event.hpp
│   │   ├── EventManager.hpp
│   │   └── IListener.hpp
│   ├── resources/
│   │   ├── ResourceManager.hpp
│   │   ├── Texture.hpp
│   │   └── Font.hpp
│   └── utils/
│       ├── Vec2.hpp
│       ├── Color.hpp
│       ├── Rect.hpp
│       └── Logger.hpp
│
├── src/
│   ├── core/
│   │   ├── Application.cpp
│   │   └── Config.cpp
│   ├── backends/
│   │   ├── SDLRenderer.cpp
│   │   ├── OpenGLRenderer.cpp
│   │   ├── MinilibXRenderer.cpp
│   │   └── VulkanRenderer.cpp
│   ├── plugins/
│   │   └── PluginManager.cpp
│   ├── ui/
│   │   ├── UISystem.cpp
│   │   ├── Window.cpp
│   │   └── Button.cpp
│   ├── events/
│   │   └── EventManager.cpp
│   ├── resources/
│   │   ├── ResourceManager.cpp
│   │   └── Texture.cpp
│   └── main.cpp
│
├── plugins/
│   ├── video-player/
│   │   ├── CMakeLists.txt
│   │   ├── VideoPlayerPlugin.hpp
│   │   └── VideoPlayerPlugin.cpp
│   ├── image-viewer/
│   │   ├── CMakeLists.txt
│   │   ├── ImageViewerPlugin.hpp
│   │   └── ImageViewerPlugin.cpp
│   └── terminal/
│       ├── CMakeLists.txt
│       ├── TerminalPlugin.hpp
│       └── TerminalPlugin.cpp
│
├── examples/
│   ├── basic-window/
│   ├── custom-plugin/
│   └── renderer-comparison/
│
├── tests/
│   ├── unit/
│   └── integration/
│
└── assets/
    ├── textures/
    ├── fonts/
    └── config/
        └── default-config.json
```

---

## 🚀 Flux de Développement

### Phase 1 : MVP (Minimum Viable Product)
1. Implémenter IRenderer avec SDLRenderer
2. Application de base avec boucle de rendu
3. Système d'événements basique
4. Un widget simple (Window + Button)

### Phase 2 : Plugin System
1. Interface IPlugin
2. PluginManager avec chargement dynamique
3. Premier plugin : ImageViewerPlugin
4. Documentation pour créer un plugin

### Phase 3 : UI System Complet
1. Tous les widgets de base
2. Système de layout
3. Thèmes
4. Gestion complète des événements

### Phase 4 : Backends Additionnels
1. OpenGLRenderer
2. MinilibXRenderer
3. Tests de performance comparatifs

### Phase 5 : Plugins Avancés
1. VideoPlayerPlugin
2. TextEditorPlugin
3. TerminalPlugin

### Phase 6 : Polish & Distribution
1. Documentation complète
2. Exemples et tutoriels
3. CI/CD
4. Release v1.0

---

## 🎯 Cas d'Usage

### 1. Visualiseur Multimédia
```cpp
Application::init({
    .renderer = "SDL",
    .plugins = {"video-player", "image-viewer", "audio-player"}
});
```

### 2. Environnement de Développement
```cpp
Application::init({
    .renderer = "OpenGL",
    .plugins = {"text-editor", "terminal", "file-browser"}
});
```

### 3. Dashboard d'Analyse
```cpp
Application::init({
    .renderer = "Vulkan",
    .plugins = {"data-visualization", "graph-plotter"}
});
```

---

## 🤝 Contribution

### Comment contribuer
1. Fork le projet
2. Créer une branche (`git checkout -b feature/amazing-feature`)
3. Commit les changements (`git commit -m 'Add amazing feature'`)
4. Push sur la branche (`git push origin feature/amazing-feature`)
5. Ouvrir une Pull Request

### Standards de code
- **Style** : Google C++ Style Guide
- **Naming** : PascalCase pour classes, camelCase pour méthodes
- **Documentation** : Doxygen pour toutes les API publiques
- **Tests** : Coverage minimum 80%

---

## 📄 Licence

Ce projet est sous licence **MIT** - voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

## 📚 Ressources Additionnelles

### Documentation des backends
- [SDL2 Documentation](https://wiki.libsdl.org/)
- [OpenGL Tutorial](https://learnopengl.com/)
- [Vulkan Tutorial](https://vulkan-tutorial.com/)

### Patterns de conception
- **Game Programming Patterns** par Robert Nystrom
- **Design Patterns** par Gang of Four

### Communauté
- Discord : [Lien à créer]
- Forum : [Lien à créer]
- Wiki : [Lien à créer]

---

## 🎓 Pour École 42

One peut être utilisé comme base pour plusieurs projets 42 :
- **so_long** : Utiliser MinilibXRenderer
- **cub3d** / **miniRT** : Raycasting avec OpenGLRenderer
- **scop** : Visualiseur 3D avec OpenGLRenderer

Le backend MinilibX est spécialement conçu pour être compatible avec les exigences de l'École 42.

---

**Version** : 0.1.0-alpha  
**Dernière mise à jour** : Décembre 2024  
**Auteur** : [Votre nom]  
**Contact** : [Votre email]