# 📚 Tutoriel UML Complet - Projet AllInOne

## Table des Matières
1. [Introduction à UML](#1-introduction-à-uml)
2. [Diagramme de Classes](#2-diagramme-de-classes)
3. [Les Relations UML](#3-les-relations-uml)
4. [Patterns de Conception](#4-patterns-de-conception)
5. [Analyse du Projet AllInOne](#5-analyse-du-projet-allinone)
6. [Cas d'Utilisation Pratiques](#6-cas-dutilisation-pratiques)
7. [Bonnes Pratiques](#7-bonnes-pratiques)

---

## 1. Introduction à UML

### 1.1 Qu'est-ce qu'UML ?

**UML (Unified Modeling Language)** est un langage de modélisation standardisé utilisé pour :
- **Visualiser** l'architecture d'un système
- **Spécifier** les structures et comportements
- **Documenter** les décisions de conception
- **Communiquer** entre développeurs et parties prenantes

### 1.2 Pourquoi utiliser UML ?

Dans le projet **AllInOne**, UML nous permet de :
- Comprendre rapidement l'architecture multi-backend
- Visualiser le système de plugins extensible
- Documenter les interactions entre composants
- Planifier l'évolution du système

---

## 2. Diagramme de Classes

### 2.1 Structure de Base

Un diagramme de classes est composé de trois sections principales :

```text
╔═════════════════════╗
║   Nom de Classe     ║  ← Section 1 : Nom
╠═════════════════════╣
║ - attribut: type    ║  ← Section 2 : Attributs (privés)
║ + attribut: type    ║                    (publics)
╠═════════════════════╣
║ + méthode(): type   ║  ← Section 3 : Méthodes
║ - méthode(): type   ║
╚═════════════════════╝
```

### 2.2 Visibilité des Membres

- **`+`** Public : Accessible de partout
- **`-`** Private : Accessible uniquement dans la classe
- **`#`** Protected : Accessible dans la classe et ses dérivées
- **`~`** Package : Accessible dans le même package (Java)

### 2.3 Exemple Concret : IRenderer

Voici l'interface `IRenderer` de notre projet :

```text
╔═══════════════════════════════════════╗
║         «interface»                   ║
║           IRenderer                   ║
╠═══════════════════════════════════════╣
║                                       ║
╠═══════════════════════════════════════╣
║ + init(w: int, h: int): bool         ║
║ + shutdown(): void                    ║
║ + clear(color: Color): void           ║
║ + present(): void                     ║
║ + drawPixel(x: int, y: int,           ║
║             color: Color): void       ║
║ + drawLine(x1: int, y1: int,          ║
║            x2: int, y2: int): void    ║
║ + drawRect(rect: Rect,                ║
║            color: Color): void        ║
║ + getSize(): Vec2                     ║
╚═══════════════════════════════════════╝
```

**Pourquoi une interface ?**
- Définit un **contrat** que tous les renderers doivent respecter
- Permet le **polymorphisme** : Application peut utiliser n'importe quel renderer
- Facilite l'**extensibilité** : Ajouter un nouveau backend = implémenter IRenderer

### 2.4 Exemple Concret : SDLRenderer

```text
╔═══════════════════════════════════════╗
║           SDLRenderer                 ║
╠═══════════════════════════════════════╣
║ - window: SDL_Window*                 ║
║ - renderer: SDL_Renderer*             ║
║ - width: int                          ║
║ - height: int                         ║
╠═══════════════════════════════════════╣
║ + init(w: int, h: int): bool         ║
║ + shutdown(): void                    ║
║ + clear(color: Color): void           ║
║ + present(): void                     ║
║ + drawPixel(x: int, y: int,           ║
║             color: Color): void       ║
║ - convertColor(color: Color):         ║
║   SDL_Color                           ║
╚═══════════════════════════════════════╝
```

**Points clés :**
- Attributs **privés** (`-`) : `window` et `renderer` encapsulés
- Méthodes **publiques** (`+`) : implémentation de l'interface
- Méthode **privée** (`-`) : `convertColor` est un détail d'implémentation

---

## 3. Les Relations UML

### 3.1 Héritage (Généralisation)

**Symbole :** Flèche avec triangle vide pointant vers la classe parent

```text
         ╔══════════════╗
         ║ «interface»  ║
         ║  IRenderer   ║
         ╚══════════════╝
               △
               ║
       ┌───────┴────────┐
       │                │
  ╔══════════╗    ╔═════════════╗
  ║   SDL    ║    ║   OpenGL    ║
  ║ Renderer ║    ║   Renderer  ║
  ╚══════════╝    ╚═════════════╝
```

**Dans notre projet :**
```cpp
// IRenderer.hpp - Interface
class IRenderer {
public:
    virtual bool init(int width, int height) = 0;
    virtual void clear(const Color& color) = 0;
    // ... autres méthodes virtuelles pures
};

// SDLRenderer.hpp - Implémentation
class SDLRenderer : public IRenderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
public:
    bool init(int width, int height) override {
        window = SDL_CreateWindow("AllInOne", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            width, height, 
            SDL_WINDOW_SHOWN);
        // ...
        return window != nullptr;
    }
    
    void clear(const Color& color) override {
        SDL_SetRenderDrawColor(renderer, 
            color.r, color.g, color.b, 255);
        SDL_RenderClear(renderer);
    }
};
```

**Avantages :**
- **Polymorphisme** : On peut écrire du code générique qui fonctionne avec tous les renderers
- **Extensibilité** : Ajouter un nouveau backend sans modifier le code existant
- **Testabilité** : Facile de créer des mocks pour les tests

### 3.2 Association

**Symbole :** Simple ligne entre deux classes

Indique qu'une classe "connaît" une autre classe.

**Exemple :**
```text
╔══════════════╗          ╔══════════════╗
║  Application ║ ──────── ║  IRenderer   ║
╚══════════════╝          ╚══════════════╝
       uses ────────────>
```

**Code correspondant :**
```cpp
class Application {
private:
    IRenderer* renderer; // Pointeur vers un renderer
    
public:
    void setRenderer(IRenderer* r) {
        renderer = r;
    }
    
    void renderFrame() {
        renderer->clear(Color{0, 0, 0});
        // Utilisation du renderer...
        renderer->present();
    }
};
```

### 3.3 Agrégation

**Symbole :** Ligne avec losange vide du côté du conteneur

Relation "a un" où les objets peuvent exister indépendamment.

```text
╔══════════════╗  ◇────── ╔══════════════╗
║  Application ║          ║ PluginManager║
╚══════════════╝          ╚══════════════╝
   (agrégation - possession faible)
```

**Caractéristiques :**
- Le `PluginManager` peut exister sans `Application`
- Si `Application` est détruite, `PluginManager` peut continuer d'exister
- Relation de "possession faible"

**Code correspondant :**
```cpp
class Application {
private:
    PluginManager* pluginManager; // Pointeur non-owning
    
public:
    Application() : pluginManager(nullptr) {}
    
    void setPluginManager(PluginManager* pm) {
        pluginManager = pm; // Ne possède pas, juste référence
    }
    
    ~Application() {
        // NE détruit PAS le PluginManager
        pluginManager = nullptr;
    }
};
```

### 3.4 Composition

**Symbole :** Ligne avec losange plein du côté du conteneur

Relation "est composé de" où les parties ne peuvent exister sans le tout.

```text
╔══════════════╗  ◆────── ╔══════════════╗
║  Application ║          ║  UISystem    ║
╚══════════════╝          ╚══════════════╝
   (composition - possession forte)
```

**Caractéristiques :**
- `UISystem` appartient **exclusivement** à `Application`
- Si `Application` est détruite, `UISystem` est également détruit
- Relation de "possession forte"

**Code correspondant :**
```cpp
class Application {
private:
    UISystem* uiSystem; // Pointeur owning
    
public:
    Application() {
        uiSystem = new UISystem(); // Crée et possède
    }
    
    ~Application() {
        delete uiSystem; // Détruit quand Application est détruite
        uiSystem = nullptr;
    }
};

// Ou avec smart pointer (meilleure pratique)
class Application {
private:
    std::unique_ptr<UISystem> uiSystem;
    
public:
    Application() : uiSystem(std::make_unique<UISystem>()) {}
    // Pas besoin de destructeur, unique_ptr gère la mémoire
};
```

### 3.5 Dépendance

**Symbole :** Flèche en pointillés

Indique qu'une classe utilise temporairement une autre classe.

```text
╔══════════════╗  ┄┄┄┄┄┄> ╔══════════════╗
║ VideoPlayer  ║           ║  IRenderer   ║
║   Plugin     ║           ╚══════════════╝
╚══════════════╝
   (dépendance - usage temporaire)
```

**Code correspondant :**
```cpp
class VideoPlayerPlugin : public IPlugin {
public:
    void onRender(IRenderer* renderer) override {
        // Utilise renderer temporairement
        renderer->drawRect(videoRect, Color{0, 0, 0});
        renderer->present();
        // Ne stocke pas de référence au renderer
    }
};
```

### 3.6 Tableau Récapitulatif des Relations

| Relation | Symbole | Force | Durée de vie | Exemple AllInOne |
|----------|---------|-------|--------------|------------------|
| **Héritage** | `───▷` | Très forte | Couplage fort | `SDLRenderer` hérite de `IRenderer` |
| **Composition** | `───◆` | Forte | Dépendante | `Application` possède `UISystem` |
| **Agrégation** | `───◇` | Moyenne | Indépendante | `Application` référence `PluginManager` |
| **Association** | `───` | Faible | Variable | `Window` connaît `Button` |
| **Dépendance** | `- - ->` | Très faible | Temporaire | `Plugin::onRender(IRenderer*)` |

---

## 4. Patterns de Conception

### 4.1 Singleton Pattern

**Définition :** Garantit qu'une classe n'a qu'une seule instance et fournit un point d'accès global.

**Représentation UML :**
```text
╔═══════════════════════════════════╗
║  Application «Singleton»          ║
╠═══════════════════════════════════╣
║ - instance: Application* {static} ║
╠═══════════════════════════════════╣
║ - Application() {constructor}     ║
║ + getInstance(): Application*     ║
║   {static}                        ║
╚═══════════════════════════════════╝
```

**Implémentation dans AllInOne :**
```cpp
// Application.hpp
class Application {
private:
    // Instance unique (static)
    static Application* instance;
    
    // Constructeur privé (empêche l'instanciation externe)
    Application() 
        : renderer(nullptr)
        , pluginManager(nullptr)
        , uiSystem(nullptr)
        , isRunning(false) 
    {}
    
    // Supprimer le constructeur de copie
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    
    // Membres
    IRenderer* renderer;
    PluginManager* pluginManager;
    UISystem* uiSystem;
    bool isRunning;
    
public:
    // Méthode pour obtenir l'instance unique
    static Application* getInstance() {
        if (instance == nullptr) {
            instance = new Application();
        }
        return instance;
    }
    
    bool init(const Config& config) {
        // Initialisation...
        return true;
    }
    
    void run() {
        isRunning = true;
        while (isRunning) {
            // Game loop...
        }
    }
};

// Application.cpp
Application* Application::instance = nullptr;

// Utilisation
int main() {
    Application* app = Application::getInstance();
    app->init(config);
    app->run();
    
    // Pas besoin de new/delete
    // Toujours la même instance
    Application* sameApp = Application::getInstance();
    // sameApp == app (true)
}
```

**Avantages :**
- ✅ Un seul point d'accès global à l'application
- ✅ Contrôle strict de l'instanciation
- ✅ Initialisation paresseuse (lazy initialization)

**Inconvénients :**
- ❌ Difficile à tester (état global)
- ❌ Couplage fort
- ❌ Problèmes de multi-threading si mal implémenté

**Autres Singletons dans AllInOne :**
- `PluginManager` : Un seul gestionnaire de plugins
- `EventManager` : Une seule file d'événements
- `ResourceManager` : Un seul cache de ressources

### 4.2 Strategy Pattern (via Interfaces)

**Définition :** Permet de définir une famille d'algorithmes et de les rendre interchangeables.

**Représentation UML :**
```text
╔══════════════╗          ╔═══════════════════╗
║  Application ║ ──────── ║  «interface»      ║
╚══════════════╝          ║    IRenderer      ║
                          ╚═══════════════════╝
                                   △
                   ┌───────────────┼───────────────┐
                   │               │               │
             ╔══════════╗    ╔══════════╗   ╔══════════╗
             ║   SDL    ║    ║  OpenGL  ║   ║  Vulkan  ║
             ║ Renderer ║    ║ Renderer ║   ║ Renderer ║
             ╚══════════╝    ╚══════════╝   ╚══════════╝
```

**Exemple concret :**
```cpp
// Configuration au runtime
class Application {
private:
    IRenderer* renderer;
    
public:
    void setRenderer(const std::string& backend) {
        if (backend == "SDL") {
            renderer = new SDLRenderer();
        } else if (backend == "OpenGL") {
            renderer = new OpenGLRenderer();
        } else if (backend == "Vulkan") {
            renderer = new VulkanRenderer();
        }
        
        renderer->init(800, 600);
    }
    
    void renderFrame() {
        // Le même code fonctionne avec tous les backends !
        renderer->clear(Color{30, 30, 30});
        renderer->drawRect(Rect{100, 100, 200, 150}, Color{255, 0, 0});
        renderer->present();
    }
};

// Utilisation
Application app;
app.setRenderer("SDL");     // Utilise SDL
app.renderFrame();          // Rendu avec SDL

app.setRenderer("Vulkan");  // Change pour Vulkan
app.renderFrame();          // Rendu avec Vulkan (même code !)
```

**Avantages :**
- ✅ Changement de comportement à l'exécution
- ✅ Code client indépendant de l'implémentation
- ✅ Facilite l'ajout de nouveaux backends

### 4.3 Plugin Architecture

**Définition :** Permet d'étendre les fonctionnalités sans modifier le code de base.

**Représentation UML :**
```text
╔═══════════════════╗         ╔══════════════════╗
║  PluginManager    ║ ◆────── ║  «interface»   ║
║                   ║         ║     IPlugin      ║
╚═══════════════════╝         ╚══════════════════╝
                                       △
                              ┌────────┼────────┐
                              │        │        │
                        ╔══════════╗ ╔══════════╗
                        ║  Video   ║ ║  Image   ║
                        ║  Player  ║ ║  Viewer  ║
                        ╚══════════╝ ╚══════════╝
```

**Implémentation :**
```cpp
// IPlugin.hpp - Interface commune
class IPlugin {
public:
    virtual ~IPlugin() = default;
    
    virtual bool onInit(PluginContext* ctx) = 0;
    virtual void onShutdown() = 0;
    virtual void onUpdate(float deltaTime) = 0;
    virtual void onRender(IRenderer* renderer) = 0;
    virtual bool onEvent(const Event& event) = 0;
    
    virtual std::string getName() const = 0;
    virtual std::string getVersion() const = 0;
    virtual bool isEnabled() const = 0;
};

// VideoPlayerPlugin.cpp - Plugin concret
class VideoPlayerPlugin : public IPlugin {
private:
    FFmpegDecoder* decoder;
    Texture* currentFrame;
    bool isPlaying;
    
public:
    bool onInit(PluginContext* ctx) override {
        decoder = new FFmpegDecoder();
        currentFrame = nullptr;
        isPlaying = false;
        return true;
    }
    
    void onUpdate(float dt) override {
        if (isPlaying && decoder) {
            currentFrame = decoder->getNextFrame();
        }
    }
    
    void onRender(IRenderer* renderer) override {
        if (currentFrame) {
            renderer->drawTexture(currentFrame, videoRect);
        }
    }
    
    std::string getName() const override {
        return "VideoPlayer";
    }
};

// PluginManager.cpp - Chargement dynamique
class PluginManager {
private:
    std::map<std::string, IPlugin*> plugins;
    std::vector<void*> loadedLibraries; // Handles .so/.dll
    
public:
    bool loadPlugin(const std::string& path) {
        // Charger la bibliothèque dynamique
        void* handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle) {
            return false;
        }
        
        // Obtenir la fonction de création
        typedef IPlugin* (*CreatePluginFunc)();
        CreatePluginFunc createPlugin = 
            (CreatePluginFunc)dlsym(handle, "createPlugin");
        
        if (!createPlugin) {
            dlclose(handle);
            return false;
        }
        
        // Créer l'instance du plugin
        IPlugin* plugin = createPlugin();
        plugin->onInit(&context);
        
        // Stocker
        plugins[plugin->getName()] = plugin;
        loadedLibraries.push_back(handle);
        
        return true;
    }
    
    void updateAll(float dt) {
        for (auto& [name, plugin] : plugins) {
            if (plugin->isEnabled()) {
                plugin->onUpdate(dt);
            }
        }
    }
    
    void renderAll(IRenderer* renderer) {
        for (auto& [name, plugin] : plugins) {
            if (plugin->isEnabled()) {
                plugin->onRender(renderer);
            }
        }
    }
};

// Utilisation
PluginManager mgr;
mgr.loadPlugin("./plugins/libvideoplayer.so");
mgr.loadPlugin("./plugins/libimageviewer.so");

// Dans la game loop
while (running) {
    mgr.updateAll(deltaTime);
    mgr.renderAll(renderer);
}
```

---

## 5. Analyse du Projet AllInOne

### 5.1 Architecture Globale

Le projet AllInOne suit une architecture en couches modulaire :

```text
         ╔════════════════════════════════════╗
         ║      COUCHE PLUGINS                ║
         ║  VideoPlayer, ImageViewer, etc.    ║
         ╚════════════════════════════════════╝
                        ▼
         ╔════════════════════════════════════╗
         ║     COUCHE UI & WIDGETS            ║
         ║  UISystem, Window, Button          ║
         ╚════════════════════════════════════╝
                        ▼
         ╔════════════════════════════════════╗
         ║   COUCHE APPLICATION CORE          ║
         ║  Application, EventManager, etc.   ║
         ╚════════════════════════════════════╝
                        ▼
         ╔════════════════════════════════════╗
         ║  COUCHE ABSTRACTION RENDU          ║
         ║        IRenderer                   ║
         ╚════════════════════════════════════╝
                        ▼
         ╔════════════════════════════════════╗
         ║   COUCHE BACKENDS                  ║
         ║  SDL, OpenGL, Vulkan, MinilibX     ║
         ╚════════════════════════════════════╝
```

### 5.2 Diagramme Complet Annoté

```text
╔═════════════════════════════════════════════════════════════════╗
║                      SYSTÈME DE RENDU                           ║
╚═════════════════════════════════════════════════════════════════╝

        ╔══════════════════════════════════╗
        ║     «interface»                  ║
        ║       IRenderer                  ║  ← Interface polymorphique
        ║                                  ║     Abstraction du rendu
        ║  + init(w, h: int): bool        ║
        ║  + clear(color: Color): void    ║
        ║  + drawRect(...): void          ║
        ║  + present(): void              ║
        ╚══════════════════════════════════╝
                      △
          ┌───────────┼──────────┬──────────────┐
          │           │          │              │
     ╔═════════╗ ╔═════════╗ ╔═════════╗ ╔══════════╗
     ║   SDL   ║ ║ OpenGL  ║ ║ MinilibX║ ║  Vulkan  ║  ← Implémentations
     ║Renderer ║ ║Renderer ║ ║Renderer ║ ║ Renderer ║     concrètes
     ╚═════════╝ ╚═════════╝ ╚═════════╝ ╚══════════╝
     
     Chaque renderer:
     - Encapsule les détails de son API
     - Implémente l'interface IRenderer
     - Peut être échangé à runtime

╔═════════════════════════════════════════════════════════════════╗
║                    SYSTÈME DE PLUGINS                           ║
╚═════════════════════════════════════════════════════════════════╝

        ╔══════════════════════════════════╗
        ║     «interface»                  ║
        ║       IPlugin                    ║  ← Contrat pour plugins
        ║                                  ║
        ║  + onInit(ctx): bool            ║
        ║  + onUpdate(dt: float): void    ║
        ║  + onRender(r: IRenderer*): void║
        ║  + getName(): string            ║
        ╚══════════════════════════════════╝
                      △
          ┌───────────┴───────────┐
          │                       │
     ╔═════════════╗      ╔══════════════╗
     ║VideoPlayer  ║      ║ ImageViewer  ║  ← Plugins étendant
     ║   Plugin    ║      ║   Plugin     ║     les fonctionnalités
     ╚═════════════╝      ╚══════════════╝
     
     Plugins = extensions dynamiques (.so/.dll)
     Chargés au runtime sans recompilation

        ╔══════════════════════════════════╗
        ║  PluginManager «Singleton»       ║  ← Gestion centralisée
        ║                                  ║     des plugins
        ║  - plugins: map<string, IPlugin*>║
        ║  + loadPlugin(path): bool       ║
        ║  + updateAll(dt): void          ║
        ║  + renderAll(r): void           ║
        ╚══════════════════════════════════╝
                      ◆
                      │ (composition)
                      │
              ╔═══════▼══════╗
              ║   IPlugin*   ║
              ╚══════════════╝

╔═════════════════════════════════════════════════════════════════╗
║                  CŒUR DE L'APPLICATION                          ║
╚═════════════════════════════════════════════════════════════════╝

        ╔══════════════════════════════════╗
        ║   Application «Singleton»        ║  ← Orchestrateur central
        ║                                  ║     Point d'entrée
        ║  - renderer: IRenderer*         ║  ◇─┐
        ║  - pluginMgr: PluginManager*    ║  ◇─┤ Agrégation
        ║  - uiSystem: UISystem*          ║  ◆─┤ Composition
        ║  - resMgr: ResourceManager*     ║  ◆─┤
        ║  - eventMgr: EventManager*      ║  ◆─┘
        ║                                  ║
        ║  + getInstance(): Application*   ║
        ║  + init(config: Config): bool   ║
        ║  + run(): void                  ║
        ╚══════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════╗
║                  SYSTÈMES AUXILIAIRES                           ║
╚═════════════════════════════════════════════════════════════════╝

   ╔════════════════╗    ╔═════════════════╗    ╔════════════════╗
   ║  EventManager  ║    ║ ResourceManager ║    ║   UISystem     ║
   ║  «Singleton»   ║    ║   «Singleton»   ║    ║                ║
   ║                ║    ║                 ║    ║                ║
   ║  - eventQueue  ║    ║  - textures: map║    ║  - windows[]   ║
   ║  - listeners   ║    ║  - fonts: map   ║    ║  - widgets[]   ║
   ║                ║    ║                 ║    ║                ║
   ║  + pushEvent() ║    ║  + loadTexture()║    ║  + createWin() ║
   ║  + subscribe() ║    ║  + loadFont()   ║    ║  + render()    ║
   ╚════════════════╝    ╚═════════════════╝    ╚════════════════╝

╔═════════════════════════════════════════════════════════════════╗
║                  TYPES DE DONNÉES                               ║
╚═════════════════════════════════════════════════════════════════╝

   ╔══════════╗      ╔══════════╗      ╔══════════╗
   ║   Vec2   ║      ║  Color   ║      ║   Rect   ║
   ║          ║      ║          ║      ║          ║
   ║  + x: f  ║      ║  + r: u8 ║      ║  + x: i  ║
   ║  + y: f  ║      ║  + g: u8 ║      ║  + y: i  ║
   ╚══════════╝      ║  + b: u8 ║      ║  + w: i  ║
                     ╚══════════╝      ║  + h: i  ║
                                       ╚══════════╝
```

### 5.3 Flux de Données et Contrôle

**Séquence d'initialisation :**

```text
1. main()
   │
   ├──> Application::getInstance()
   │    └──> Crée instance unique
   │
   ├──> app->init(config)
   │    │
   │    ├──> Lit config.json
   │    │
   │    ├──> Crée IRenderer selon config
   │    │    └──> SDLRenderer::init(800, 600)
   │    │
   │    ├──> Crée PluginManager
   │    │    └──> loadPlugin("plugins/videoplayer.so")
   │    │         └──> VideoPlayerPlugin::onInit()
   │    │
   │    ├──> Crée UISystem
   │    │    └──> createWindow("Main", 800, 600)
   │    │
   │    ├──> Crée ResourceManager
   │    │    └──> loadTexture("assets/logo.png")
   │    │
   │    └──> Crée EventManager
   │         └──> subscribe(MOUSE_CLICK, handler)
   │
   └──> app->run()
        └──> Game Loop (voir ci-dessous)
```

**Game Loop (Boucle principale) :**

```text
╔═════════════════════════════════════╗
║  while (isRunning)                  ║
║  {                                  ║
║    ╔═════════════════════════════╗ ║
║    ║ 1. TRAITER LES ÉVÉNEMENTS   ║ ║
║    ║    eventMgr->processEvents()║ ║
║    ║    └─> Distribue aux        ║ ║
║    ║        listeners/plugins    ║ ║
║    ╚═════════════════════════════╝ ║
║              ▼                      ║
║    ╔═════════════════════════════╗ ║
║    ║ 2. UPDATE                   ║ ║
║    ║    pluginMgr->updateAll(dt) ║ ║
║    ║    └─> Chaque plugin met    ║ ║
║    ║        à jour sa logique    ║ ║
║    ╚═════════════════════════════╝ ║
║              ▼                      ║
║    ╔═════════════════════════════╗ ║
║    ║ 3. RENDER                   ║ ║
║    ║    renderer->clear(black)   ║ ║
║    ║    uiSystem->render(rdr)    ║ ║
║    ║    pluginMgr->renderAll(rdr)║ ║
║    ║    renderer->present()      ║ ║
║    ╚═════════════════════════════╝ ║
║  }                                  ║
╚═════════════════════════════════════╝
```

---

## 6. Cas d'Utilisation Pratiques

### 6.1 Ajouter un Nouveau Backend de Rendu

**Scénario :** Nous voulons ajouter un support pour **Raylib**.

**Étapes UML :**

1. **Créer la nouvelle classe** héritant de `IRenderer`
```text
        ╔══════════════════╗
        ║  «interface»   ║
        ║    IRenderer     ║
        ╚══════════════════╝
                △
                ║
                ║ (nouvel héritage)
                ║
        ╔══════════════════╗
        ║  RaylibRenderer  ║ ← NOUVEAU
        ╚══════════════════╝
```

2. **Implémentation du code :**

```cpp
// include/backends/RaylibRenderer.hpp
#pragma once
#include "core/IRenderer.hpp"
#include <raylib.h>

class RaylibRenderer : public IRenderer {
private:
    int width;
    int height;
    
    // Conversion helper
    ::Color toRaylibColor(const Color& c) {
        return ::Color{c.r, c.g, c.b, 255};
    }
    
public:
    bool init(int w, int h) override {
        width = w;
        height = h;
        InitWindow(width, height, "AllInOne - Raylib");
        SetTargetFPS(60);
        return IsWindowReady();
    }
    
    void shutdown() override {
        CloseWindow();
    }
    
    void clear(const Color& color) override {
        ClearBackground(toRaylibColor(color));
    }
    
    void present() override {
        EndDrawing();
        BeginDrawing();
    }
    
    void drawPixel(int x, int y, const Color& color) override {
        DrawPixel(x, y, toRaylibColor(color));
    }
    
    void drawRect(const Rect& rect, const Color& color) override {
        DrawRectangle(rect.x, rect.y, rect.w, rect.h, 
                      toRaylibColor(color));
    }
    
    Vec2 getSize() const override {
        return Vec2{static_cast<float>(width), 
                   static_cast<float>(height)};
    }
};
```

3. **Mise à jour de l'Application :**

```cpp
// Application.cpp
void Application::createRenderer(const std::string& backend) {
    if (backend == "SDL") {
        renderer = new SDLRenderer();
    } else if (backend == "OpenGL") {
        renderer = new OpenGLRenderer();
    } else if (backend == "Raylib") {
        renderer = new RaylibRenderer(); // ← Ajout
    }
    // ...
}
```

**Résultat :** Nouveau backend ajouté sans modifier le code existant ! ✅

### 6.2 Créer un Nouveau Plugin

**Scénario :** Plugin de **musique** pour lire des fichiers audio.

**Étapes UML :**

1. **Diagramme de classes :**

```text
        ╔══════════════════╗
        ║  «interface»     ║
        ║    IPlugin       ║
        ╚══════════════════╝
                △
                ║
                ║ (nouvel héritage)
                ║
        ╔══════════════════════╗
        ║  MusicPlayerPlugin   ║ ← NOUVEAU
        ╠══════════════════════╣
        ║ - audioEngine: Mix*  ║
        ║ - currentTrack: Track║
        ║ - volume: float      ║
        ║ - isPlaying: bool    ║
        ╠══════════════════════╣
        ║ + loadTrack(path)    ║
        ║ + play()             ║
        ║ + pause()            ║
        ║ + setVolume(v)       ║
        ╚══════════════════════╝
```

2. **Implémentation :**

```cpp
// plugins/music-player/MusicPlayerPlugin.hpp
#pragma once
#include "plugins/IPlugin.hpp"
#include <SDL_mixer.h>

class MusicPlayerPlugin : public IPlugin {
private:
    Mix_Music* currentTrack;
    float volume;
    bool isPlaying;
    
public:
    MusicPlayerPlugin() 
        : currentTrack(nullptr)
        , volume(0.5f)
        , isPlaying(false) 
    {}
    
    bool onInit(PluginContext* ctx) override {
        // Initialiser SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            return false;
        }
        Mix_VolumeMusic(static_cast<int>(volume * 128));
        return true;
    }
    
    void onShutdown() override {
        if (currentTrack) {
            Mix_FreeMusic(currentTrack);
        }
        Mix_CloseAudio();
    }
    
    void onUpdate(float deltaTime) override {
        // Vérifier si la musique est terminée
        if (isPlaying && !Mix_PlayingMusic()) {
            isPlaying = false;
        }
    }
    
    void onRender(IRenderer* renderer) override {
        // Afficher UI du player
        if (isPlaying) {
            renderer->drawRect(Rect{10, 10, 200, 50}, 
                             Color{50, 50, 50});
            // Dessiner contrôles...
        }
    }
    
    bool onEvent(const Event& event) override {
        if (event.type == EventType::KEY_PRESS) {
            if (event.key == 'P') {
                togglePlayPause();
                return true; // Event consommé
            }
        }
        return false;
    }
    
    std::string getName() const override {
        return "MusicPlayer";
    }
    
    std::string getVersion() const override {
        return "1.0.0";
    }
    
    bool isEnabled() const override {
        return true;
    }
    
    // Méthodes spécifiques
    bool loadTrack(const std::string& path) {
        if (currentTrack) {
            Mix_FreeMusic(currentTrack);
        }
        currentTrack = Mix_LoadMUS(path.c_str());
        return currentTrack != nullptr;
    }
    
    void togglePlayPause() {
        if (isPlaying) {
            Mix_PauseMusic();
            isPlaying = false;
        } else {
            Mix_ResumeMusic();
            if (!Mix_PlayingMusic()) {
                Mix_PlayMusic(currentTrack, -1); // Loop
            }
            isPlaying = true;
        }
    }
    
    void setVolume(float v) {
        volume = std::clamp(v, 0.0f, 1.0f);
        Mix_VolumeMusic(static_cast<int>(volume * 128));
    }
};

// Point d'entrée pour le chargement dynamique
extern "C" {
    IPlugin* createPlugin() {
        return new MusicPlayerPlugin();
    }
}
```

3. **CMakeLists.txt pour compiler le plugin :**

```cmake
# plugins/music-player/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MusicPlayerPlugin)

find_package(SDL2_mixer REQUIRED)

add_library(musicplayer SHARED
    MusicPlayerPlugin.cpp
)

target_include_directories(musicplayer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(musicplayer
    SDL2::mixer
)
```

4. **Utilisation :**

```cpp
// Dans l'application
PluginManager* pm = PluginManager::getInstance();
pm->loadPlugin("./plugins/libmusicplayer.so");

// Le plugin est maintenant actif !
// Appuyez sur 'P' pour play/pause
```

**Diagramme de séquence de chargement :**

```text
╭──────────╮  ╭──────────────╮  ╭─────────────╮  ╭──────────────╮
│   App    │  │ PluginManager│  │   dlopen    │  │ MusicPlayer  │
╰─────┬────╯  ╰──────┬───────╯  ╰──────┬──────╯  ╰──────┬───────╯
      │              │                 │                │
      │loadPlugin()  │                 │                │
      │─────────────>│                 │                │
      │              │ dlopen(path)    │                │
      │              │────────────────>│                │
      │              │                 │                │
      │              │   handle        │                │
      │              │<────────────────│                │
      │              │                 │                │
      │              │ dlsym("createPlugin")            │
      │              │────────────────>│                │
      │              │                 │                │
      │              │ createPlugin()  │                │
      │              │────────────────────────────────>│
      │              │                 │                │
      │              │                 │   new Instance│
      │              │                 │<───────────────│
      │              │                 │                │
      │              │ plugin->onInit()│                │
      │              │────────────────────────────────>│
      │              │                 │                │
      │              │         OK      │                │
      │              │<────────────────────────────────│
      │   true       │                 │                │
      │<─────────────│                 │                │
```

### 6.3 Gestion des Événements

**Scénario :** Un bouton dans l'UI déclenche une action dans un plugin.

**Diagramme de classes impliquées :**

```text
╔══════════════╗      ╔══════════════╗      ╔══════════════╗
║   Button     ║─────>║EventManager  ║─────>║  IListener   ║
║              ║      ║  «Singleton» ║      ║              ║
║+ onClick()   ║      ║              ║      ║+ onEvent()   ║
╚══════════════╝      ║- eventQueue  ║      ╚══════════════╝
                      ║- listeners   ║             △
                      ║              ║             │
                      ║+ pushEvent() ║             │
                      ║+ subscribe() ║      ╔══════════════╗
                      ╚══════════════╝      ║MusicPlayer   ║
                                            ║  Plugin      ║
                                            ╚══════════════╝
```

**Implémentation :**

```cpp
// 1. Définir l'événement
struct Event {
    enum Type {
        MOUSE_CLICK,
        KEY_PRESS,
        BUTTON_CLICKED,
        // ...
    };
    
    Type type;
    union {
        struct { int x, y, button; } mouse;
        struct { char key; } keyboard;
        struct { std::string buttonId; } ui;
    };
};

// 2. Le bouton émet l'événement
class Button : public IWidget {
private:
    std::string id;
    Rect bounds;
    
public:
    void onMouseClick(int x, int y) {
        if (bounds.contains(x, y)) {
            Event event;
            event.type = Event::BUTTON_CLICKED;
            event.ui.buttonId = id;
            
            EventManager::getInstance()->pushEvent(event);
        }
    }
};

// 3. Le plugin s'abonne et réagit
class MusicPlayerPlugin : public IPlugin {
public:
    bool onEvent(const Event& event) override {
        if (event.type == Event::BUTTON_CLICKED) {
            if (event.ui.buttonId == "play_button") {
                play();
                return true; // Événement consommé
            } else if (event.ui.buttonId == "stop_button") {
                stop();
                return true;
            }
        }
        return false; // Événement non traité
    }
};

// 4. EventManager distribue
class EventManager {
private:
    std::queue<Event> eventQueue;
    std::multimap<Event::Type, IListener*> listeners;
    
public:
    void pushEvent(const Event& event) {
        eventQueue.push(event);
    }
    
    void subscribe(Event::Type type, IListener* listener) {
        listeners.insert({type, listener});
    }
    
    void processEvents() {
        while (!eventQueue.empty()) {
            Event event = eventQueue.front();
            eventQueue.pop();
            
            // Trouver tous les listeners pour ce type
            auto range = listeners.equal_range(event.type);
            for (auto it = range.first; it != range.second; ++it) {
                bool consumed = it->second->onEvent(event);
                if (consumed) break; // Stop propagation
            }
        }
    }
};
```

**Séquence complète :**

```text
╭──────╮  ╭────────╮  ╭──────────╮  ╭────────────╮  ╭──────────╮
│ User │  │ Button │  │EventMgr  │  │PluginMgr   │  │ Music    │
╰───┬──╯  ╰───┬────╯  ╰────┬─────╯  ╰─────┬──────╯  ╰────┬─────╯
    │         │            │              │               │
    │ Click   │            │              │               │
    │────────>│            │              │               │
    │         │            │              │               │
    │         │ pushEvent()│              │               │
    │         │───────────>│              │               │
    │         │            │              │               │
    │         │            │ [Game Loop]  │               │
    │         │            │              │               │
    │         │            │processEvents()               │
    │         │            │<─────────────│               │
    │         │            │              │               │
    │         │            │ onEvent()    │               │
    │         │            │──────────────────────────────>│
    │         │            │              │               │
    │         │            │              │        play() │
    │         │            │              │     ┌─────────│
    │         │            │              │     │         │
    │         │            │              │     └────────>│
    │         │            │     true     │               │
    │         │            │<──────────────────────────────│
    │         │            │              │               │
```

---

## 7. Bonnes Pratiques

### 7.1 Principes SOLID

#### S - Single Responsibility Principle

**Une classe = une responsabilité**

❌ **Mauvais exemple :**
```cpp
class Application {
    void init();
    void run();
    void render();
    void loadTexture(std::string path);  // Pas sa responsabilité
    void playSound(std::string path);    // Pas sa responsabilité
    void saveConfig();                   // Pas sa responsabilité
};
```

✅ **Bon exemple :**
```cpp
class Application {
    void init();
    void run();
};

class ResourceManager {  // Responsabilité: Gérer ressources
    Texture* loadTexture(std::string path);
    Sound* loadSound(std::string path);
};

class ConfigManager {    // Responsabilité: Configuration
    void save();
    void load();
};
```

#### O - Open/Closed Principle

**Ouvert à l'extension, fermé à la modification**

❌ **Mauvais exemple :**
```cpp
class Renderer {
    void render(const std::string& backend) {
        if (backend == "SDL") {
            // Code SDL
        } else if (backend == "OpenGL") {
            // Code OpenGL
        } else if (backend == "Vulkan") {  // Modification pour ajouter
            // Code Vulkan
        }
    }
};
```

✅ **Bon exemple :**
```cpp
// Extensible via héritage, pas de modification nécessaire
class IRenderer {
    virtual void render() = 0;
};

class SDLRenderer : public IRenderer {
    void render() override { /* SDL */ }
};

class VulkanRenderer : public IRenderer {  // Extension, pas modification
    void render() override { /* Vulkan */ }
};
```

#### L - Liskov Substitution Principle

**Les sous-classes doivent être substituables à leurs classes parentes**

❌ **Mauvais exemple :**
```cpp
class Bird {
    virtual void fly() = 0;
};

class Penguin : public Bird {
    void fly() override {
        throw std::exception("Les pingouins ne volent pas!");
    }
};
```

✅ **Bon exemple :**
```cpp
class Bird {
    virtual void move() = 0;
};

class FlyingBird : public Bird {
    void move() override { fly(); }
};

class Penguin : public Bird {
    void move() override { swim(); }
};
```

**Dans AllInOne :**
```cpp
// Tous les renderers sont interchangeables
IRenderer* renderer = new SDLRenderer();
renderer->init(800, 600);      // Fonctionne

renderer = new VulkanRenderer();  // Substitution
renderer->init(800, 600);         // Fonctionne aussi
```

#### I - Interface Segregation Principle

**Ne pas forcer à implémenter des méthodes inutiles**

❌ **Mauvais exemple :**
```cpp
class IRenderer {
    virtual void drawPixel() = 0;
    virtual void drawLine() = 0;
    virtual void draw3DModel() = 0;    // Pas toujours nécessaire
    virtual void applyShader() = 0;    // Spécifique à certains backends
    virtual void enableVR() = 0;       // Très spécifique
};
```

✅ **Bon exemple :**
```cpp
// Interface de base minimale
class IRenderer {
    virtual void drawPixel() = 0;
    virtual void drawLine() = 0;
};

// Interfaces optionnelles
class I3DRenderer : public IRenderer {
    virtual void draw3DModel() = 0;
};

class IShaderRenderer : public IRenderer {
    virtual void applyShader() = 0;
};

// Implémentation selon les capacités
class SDLRenderer : public IRenderer {
    // Implémente seulement le 2D
};

class OpenGLRenderer : public I3DRenderer, public IShaderRenderer {
    // Implémente 2D, 3D et shaders
};
```

#### D - Dependency Inversion Principle

**Dépendre des abstractions, pas des implémentations**

❌ **Mauvais exemple :**
```cpp
class Application {
private:
    SDLRenderer* renderer;  // Dépendance directe sur implémentation
    
public:
    Application() {
        renderer = new SDLRenderer();  // Couplage fort
    }
};
```

✅ **Bon exemple :**
```cpp
class Application {
private:
    IRenderer* renderer;  // Dépendance sur abstraction
    
public:
    void setRenderer(IRenderer* r) {  // Injection de dépendance
        renderer = r;
    }
};

// Utilisation
Application app;
app.setRenderer(new SDLRenderer());    // Ou
app.setRenderer(new VulkanRenderer()); // Ou n'importe quelle implémentation
```

### 7.2 Conventions de Nommage UML

| Élément | Convention | Exemple |
|---------|------------|---------|
| **Classe** | PascalCase | `Application`, `PluginManager` |
| **Interface** | I + PascalCase | `IRenderer`, `IPlugin` |
| **Attribut** | camelCase | `renderer`, `isRunning` |
| **Méthode** | camelCase | `init()`, `loadPlugin()` |
| **Constante** | UPPER_SNAKE_CASE | `MAX_PLUGINS`, `DEFAULT_WIDTH` |
| **Namespace** | lowercase | `allinone::core` |

### 7.3 Patterns à Éviter

#### God Class (Classe Dieu)

❌ **Une classe qui fait tout :**
```cpp
class Application {
    void init();
    void run();
    void render();
    void processInput();
    void loadTexture();
    void playSound();
    void saveConfig();
    void loadConfig();
    void managePlugins();
    void createWindow();
    void handleEvents();
    // ... 50 autres méthodes
};
```

✅ **Diviser les responsabilités :**
```cpp
class Application {
    void init();
    void run();
};

class ResourceManager { /* Gestion ressources */ };
class PluginManager { /* Gestion plugins */ };
class EventManager { /* Gestion événements */ };
class UISystem { /* Gestion UI */ };
```

#### Circular Dependencies

❌ **A dépend de B, B dépend de A :**
```
┌──────────┐        ┌──────────┐
│    A     │───────>│    B     │
│          │        │          │
│          │<───────│          │
└──────────┘        └──────────┘
```

✅ **Utiliser une interface ou un mediator :**
```
┌──────────┐        ┌──────────┐        ┌──────────┐
│    A     │───────>│ Interface│<───────│    B     │
└──────────┘        └──────────┘        └──────────┘
```

### 7.4 Documentation UML

**Annotations utiles dans les diagrammes :**

```
┌─────────────────────────────────┐
│  ClassName                      │
│  {abstract}                     │  ← Classe abstraite
│  {singleton}                    │  ← Pattern utilisé
├─────────────────────────────────┤
│  - attribute: Type              │
│    {readonly}                   │  ← Contrainte
├─────────────────────────────────┤
│  + method(): Type               │
│    {deprecated}                 │  ← Méthode obsolète
│    {throws IOException}         │  ← Exception levée
└─────────────────────────────────┘
```

**Commentaires dans le diagramme :**
```
┌─────────────┐
│  IRenderer  │
└─────────────┘
       △
       │  ╔═══════════════════════════════════╗
       │  ║ Tous les renderers doivent       ║
       │  ║ implémenter cette interface pour ║
       │  ║ assurer la compatibilité         ║
       └──╚═══════════════════════════════════╝
```

---

## 8. Exercices Pratiques

### Exercice 1 : Modéliser un Plugin de Chat

**Objectif :** Créer un diagramme UML pour un plugin de chat.

**Spécifications :**
- Le plugin hérite de `IPlugin`
- Il gère une liste de messages (Message)
- Il a un champ de saisie (TextInput)
- Il affiche l'historique dans une fenêtre scrollable

**Solution attendue :**
```text
        ╔══════════════╗
        ║   IPlugin    ║
        ╚══════════════╝
               △
               ║
        ╔══════════════╗
        ║ ChatPlugin   ║◆──────┐
        ╠══════════════╣       │
        ║- messages[]  ║       │
        ║- textInput   ║       │
        ║- scrollPos   ║       │
        ╠══════════════╣       │
        ║+ sendMessage()║      │
        ║+ render()    ║       │
        ╚══════════════╝       │
                               ▼
                        ╔══════════════╗
                        ║   Message    ║
                        ╠══════════════╣
                        ║+ text: string║
                        ║+ author: str ║
                        ║+ timestamp   ║
                        ╚══════════════╝
```

### Exercice 2 : Relations entre Classes

**Identifiez le type de relation :**

1. `Application` possède un `UISystem` qui est détruit avec elle : **?**
2. `PluginManager` référence des `IPlugin*` : **?**
3. `SDLRenderer` implémente `IRenderer` : **?**
4. `Button::onClick()` utilise temporairement `EventManager` : **?**

**Réponses :**
1. Composition (◆)
2. Composition (◆) ou Agrégation (◇) selon ownership
3. Héritage (△)
4. Dépendance (- - ->)

### Exercice 3 : Refactoring

**Refactorez ce code en appliquant les principes SOLID :**

```cpp
class VideoPlayer {
    void loadVideo(std::string path);
    void play();
    void pause();
    void decodeFrame();        // Responsabilité codec
    void renderFrame();        // Responsabilité rendu
    void handleInput();        // Responsabilité UI
    void saveSettings();       // Responsabilité config
};
```

**Solution :**
```cpp
// Single Responsibility
class VideoDecoder {
    void loadVideo(std::string path);
    Frame* decodeFrame();
};

class VideoRenderer {
    void renderFrame(Frame* frame, IRenderer* renderer);
};

class VideoPlayerUI {
    void handleInput();
    void displayControls();
};

class VideoPlayerPlugin : public IPlugin {
private:
    VideoDecoder* decoder;
    VideoRenderer* renderer;
    VideoPlayerUI* ui;
    
public:
    void onUpdate(float dt) override {
        Frame* frame = decoder->decodeFrame();
        // ...
    }
    
    void onRender(IRenderer* r) override {
        renderer->renderFrame(currentFrame, r);
    }
    
    bool onEvent(const Event& e) override {
        return ui->handleInput(e);
    }
};
```

---

## 9. Ressources et Références

### 9.1 Outils de Modélisation

- **Draw.io** (utilisé dans ce projet) : Gratuit, web-based
- **PlantUML** : Génération de diagrammes depuis du texte
- **Visual Paradigm** : Professionnel, complet
- **StarUML** : Open-source, riche en fonctionnalités

### 9.2 Lectures Recommandées

- "Design Patterns: Elements of Reusable Object-Oriented Software" (Gang of Four)
- "Clean Architecture" by Robert C. Martin
- "Head First Design Patterns" by Freeman & Freeman
- UML 2.0 Specification (OMG)

### 9.3 Liens Utiles

- Documentation officielle UML : https://www.uml.org/
- Refactoring Guru (Patterns) : https://refactoring.guru/
- SOLID Principles : https://en.wikipedia.org/wiki/SOLID

---

## 10. Glossaire

| Terme | Définition |
|-------|------------|
| **Abstraction** | Processus de masquer les détails d'implémentation |
| **Agrégation** | Relation "a un" avec cycle de vie indépendant |
| **Association** | Relation de connaissance entre classes |
| **Classe abstraite** | Classe avec au moins une méthode virtuelle pure |
| **Composition** | Relation "est composé de" avec cycle de vie dépendant |
| **Couplage** | Degré de dépendance entre classes |
| **Encapsulation** | Masquer l'état interne d'un objet |
| **Héritage** | Relation "est un" entre classes |
| **Interface** | Contrat définissant des méthodes à implémenter |
| **Polymorphisme** | Capacité à utiliser des objets de types différents de manière uniforme |
| **Singleton** | Pattern garantissant une seule instance |

---

## Conclusion

Ce tutoriel vous a présenté :

✅ Les **bases d'UML** et des diagrammes de classes  
✅ Les **relations** entre classes (héritage, composition, etc.)  
✅ Les **patterns de conception** utilisés dans AllInOne  
✅ L'**analyse complète** de l'architecture du projet  
✅ Des **exemples pratiques** d'extension du système  
✅ Les **bonnes pratiques** SOLID et conventions  

**L'architecture AllInOne** est un excellent exemple de :
- Design modulaire et extensible
- Utilisation correcte des patterns
- Séparation des responsabilités
- Code maintenable et évolutif

Continuez à pratiquer la modélisation UML pour améliorer vos compétences en architecture logicielle !

---

**Version :** 1.0  
**Date :** Janvier 2026  
**Auteur :** Projet AllInOne  
**Licence :** MIT
