# One - Liste des Tâches (TODO)

## 📊 Vue d'ensemble du projet

**État actuel** : 🔴 Phase de conception  
**Progression globale** : 0%  
**Date de début prévue** : [À définir]  
**Version cible** : 1.0.0

---

## 🎯 Phase 1 : Setup & Infrastructure (Priorité CRITIQUE)

### 1.1 Configuration du Projet
- [ ] **P0** Créer le repository Git
  - [ ] Initialiser le dépôt GitHub/GitLab
  - [ ] Ajouter .gitignore pour C++ (build/, bin/, .vscode/, etc.)
  - [ ] Créer la structure de dossiers de base
  - [ ] Ajouter README.md initial

- [ ] **P0** Configurer CMake
  - [ ] CMakeLists.txt racine
  - [ ] CMakeLists.txt pour core/
  - [ ] CMakeLists.txt pour backends/
  - [ ] CMakeLists.txt pour plugins/
  - [ ] Détection automatique des dépendances
  - [ ] Options de compilation (Debug/Release)
  - [ ] Support multi-plateforme (Linux, macOS, Windows)

- [ ] **P0** Choisir et configurer la licence
  - [ ] Rédiger LICENSE (MIT recommandé)
  - [ ] Ajouter headers de licence dans les fichiers sources

- [ ] **P1** Mettre en place CI/CD
  - [ ] GitHub Actions ou GitLab CI
  - [ ] Build automatique sur push
  - [ ] Tests automatiques
  - [ ] Vérification de style de code (clang-format)

### 1.2 Documentation Initiale
- [ ] **P1** Créer CONTRIBUTING.md
  - [ ] Guide de contribution
  - [ ] Standards de code
  - [ ] Processus de review

- [ ] **P1** Créer docs/architecture.md
  - [ ] Diagrammes UML
  - [ ] Explication des composants
  - [ ] Flux de données

- [ ] **P2** Créer CODE_OF_CONDUCT.md

**Temps estimé Phase 1** : 1-2 semaines

---

## 🎨 Phase 2 : Core Engine - Rendering Abstraction (Priorité HAUTE)

### 2.1 Interface IRenderer
- [ ] **P0** Créer include/core/IRenderer.hpp
  - [ ] Définir toutes les méthodes virtuelles pures
  - [ ] Documenter chaque méthode (Doxygen)
  - [ ] Ajouter des exemples d'utilisation en commentaires

### 2.2 Classes Utilitaires
- [ ] **P0** Implémenter utils/Vec2.hpp
  - [ ] Constructeurs
  - [ ] Opérateurs (+, -, *, /)
  - [ ] Méthodes (length, normalize, dot, distance)
  - [ ] Tests unitaires

- [ ] **P0** Implémenter utils/Color.hpp
  - [ ] Constructeurs (RGBA, hex)
  - [ ] Conversions (toHex, fromHex)
  - [ ] Couleurs prédéfinies (WHITE, BLACK, etc.)
  - [ ] Opérateurs et interpolation (lerp)
  - [ ] Tests unitaires

- [ ] **P0** Implémenter utils/Rect.hpp
  - [ ] Constructeurs
  - [ ] Méthodes (contains, intersects, getCenter)
  - [ ] Tests unitaires

### 2.3 Backend SDL (Premier backend)
- [ ] **P0** Installer et configurer SDL2
  - [ ] Ajouter SDL2 aux dépendances CMake
  - [ ] Tester l'installation

- [ ] **P0** Implémenter SDLRenderer.hpp/.cpp
  - [ ] Constructeur/Destructeur
  - [ ] init(width, height)
  - [ ] shutdown()
  - [ ] clear(color)
  - [ ] present()
  - [ ] drawPixel(x, y, color)
  - [ ] drawLine(x1, y1, x2, y2, color)
  - [ ] drawRect(rect, color, filled)
  - [ ] getSize()

- [ ] **P0** Tester SDLRenderer
  - [ ] Test : Ouvrir une fenêtre
  - [ ] Test : Dessiner des pixels
  - [ ] Test : Dessiner des lignes
  - [ ] Test : Dessiner des rectangles
  - [ ] Test : Clear avec différentes couleurs

### 2.4 Gestion des Textures
- [ ] **P1** Créer resources/Texture.hpp
  - [ ] Structure de données
  - [ ] Méthodes de chargement

- [ ] **P1** Implémenter loadTexture dans SDLRenderer
  - [ ] Support PNG avec stb_image
  - [ ] Support JPEG
  - [ ] Gestion des erreurs

- [ ] **P1** Implémenter drawTexture dans SDLRenderer

**Temps estimé Phase 2** : 2-3 semaines

---

## 🎮 Phase 3 : Application Core (Priorité HAUTE)

### 3.1 Classe Application (Singleton)
- [ ] **P0** Créer core/Application.hpp
  - [ ] Pattern Singleton
  - [ ] Attributs privés (renderer, isRunning, etc.)
  - [ ] Méthodes publiques (getInstance, init, run, shutdown)

- [ ] **P0** Implémenter core/Application.cpp
  - [ ] getInstance()
  - [ ] init(config) - Initialisation de tous les composants
  - [ ] run() - Boucle principale
  - [ ] shutdown() - Nettoyage

### 3.2 Configuration
- [ ] **P0** Créer core/Config.hpp
  - [ ] Structure de configuration
  - [ ] Paramètres par défaut

- [ ] **P1** Implémenter chargement depuis JSON
  - [ ] Ajouter nlohmann/json
  - [ ] loadFromFile(path)
  - [ ] saveToFile(path)
  - [ ] Validation des paramètres

### 3.3 Boucle de Rendu
- [ ] **P0** Implémenter la boucle principale dans Application::run()
  - [ ] Calcul du deltaTime
  - [ ] Limitation du FPS
  - [ ] Gestion de isRunning

- [ ] **P0** Créer un exemple minimal (main.cpp)
  - [ ] Initialisation
  - [ ] Fenêtre avec couleur de fond
  - [ ] Fermeture propre

### 3.4 Logger System
- [ ] **P1** Créer utils/Logger.hpp (Singleton)
  - [ ] LogLevel enum
  - [ ] Méthodes : info, warning, error, debug

- [ ] **P1** Implémenter utils/Logger.cpp
  - [ ] Sortie console avec couleurs
  - [ ] Sortie fichier
  - [ ] Timestamp automatique
  - [ ] Configuration du niveau de log

**Temps estimé Phase 3** : 2-3 semaines

---

## ⚡ Phase 4 : Event System (Priorité HAUTE)

### 4.1 Structures d'Événements
- [ ] **P0** Créer events/Event.hpp
  - [ ] Structure Event
  - [ ] EventType enum (complet)
  - [ ] EventData union

- [ ] **P0** Créer events/IListener.hpp
  - [ ] Interface avec onEvent(event)

### 4.2 EventManager
- [ ] **P0** Créer events/EventManager.hpp (Singleton)
  - [ ] Queue d'événements
  - [ ] Map des listeners

- [ ] **P0** Implémenter events/EventManager.cpp
  - [ ] pushEvent(event)
  - [ ] subscribe(type, listener)
  - [ ] unsubscribe(type, listener)
  - [ ] processEvents()
  - [ ] clearQueue()

### 4.3 Intégration avec SDL
- [ ] **P0** Implémenter pollEvents() dans SDLRenderer
  - [ ] Conversion SDL_Event → Event
  - [ ] Push dans EventManager
  - [ ] Tous les types d'événements clavier/souris/fenêtre

### 4.4 Tests
- [ ] **P1** Tester le système d'événements
  - [ ] Test : Fermeture de fenêtre
  - [ ] Test : Clavier (KEY_PRESSED/RELEASED)
  - [ ] Test : Souris (clic, mouvement)
  - [ ] Test : Redimensionnement

**Temps estimé Phase 4** : 1-2 semaines

---

## 🎨 Phase 5 : UI System - Widgets de Base (Priorité MOYENNE)

### 5.1 Interface IWidget
- [ ] **P0** Créer ui/IWidget.hpp
  - [ ] Méthodes virtuelles pures
  - [ ] Documentation complète

### 5.2 UISystem
- [ ] **P0** Créer ui/UISystem.hpp
  - [ ] Gestion des widgets
  - [ ] Gestion du focus
  - [ ] Gestion des événements UI

- [ ] **P0** Implémenter ui/UISystem.cpp
  - [ ] createWindow(title, w, h)
  - [ ] handleEvents(events)
  - [ ] render(renderer)
  - [ ] update(deltaTime)

### 5.3 Widget Window
- [ ] **P0** Créer ui/Window.hpp (hérite de IWidget)
  - [ ] Attributs (title, bounds, children)
  - [ ] Méthodes (addWidget, removeWidget)

- [ ] **P0** Implémenter ui/Window.cpp
  - [ ] render() - Dessiner la fenêtre
  - [ ] handleEvent() - Gestion drag/resize
  - [ ] Gestion des widgets enfants

### 5.4 Widget Button
- [ ] **P0** Créer ui/Button.hpp
  - [ ] Callback onClick
  - [ ] États (normal, hover, pressed)

- [ ] **P0** Implémenter ui/Button.cpp
  - [ ] render() avec les 3 états
  - [ ] handleEvent() - Détection clic
  - [ ] Animation hover

### 5.5 Widgets Additionnels
- [ ] **P1** Label (texte statique)
- [ ] **P1** TextBox (saisie de texte)
- [ ] **P2** CheckBox
- [ ] **P2** Slider
- [ ] **P2** Panel (conteneur)
- [ ] **P2** ScrollBar

### 5.6 Intégration
- [ ] **P0** Intégrer UISystem dans Application
- [ ] **P0** Créer un exemple avec plusieurs widgets
- [ ] **P1** Tests d'interaction

**Temps estimé Phase 5** : 3-4 semaines

---

## 📦 Phase 6 : Resource Manager (Priorité MOYENNE)

### 6.1 ResourceManager de Base
- [ ] **P0** Créer resources/ResourceManager.hpp (Singleton)
  - [ ] Maps pour chaque type de ressource
  - [ ] Cache automatique

- [ ] **P0** Implémenter resources/ResourceManager.cpp
  - [ ] loadTexture(path)
  - [ ] getTexture(path)
  - [ ] unloadTexture(path)
  - [ ] unloadAll()

### 6.2 Support Multi-formats
- [ ] **P1** Textures : PNG, JPEG, BMP
- [ ] **P1** Fonts : TTF avec FreeType
  - [ ] Créer resources/Font.hpp
  - [ ] Implémenter chargement et rendu

- [ ] **P2** Audio : WAV, MP3 avec PortAudio
  - [ ] Créer resources/Sound.hpp
  - [ ] Implémenter chargement et lecture

### 6.3 Tests
- [ ] **P1** Tester le chargement de différents formats
- [ ] **P1** Tester le cache (éviter les doublons)
- [ ] **P1** Tester le déchargement

**Temps estimé Phase 6** : 2 semaines

---

## 🔌 Phase 7 : Plugin System (Priorité HAUTE)

### 7.1 Interface IPlugin
- [ ] **P0** Créer plugins/IPlugin.hpp
  - [ ] Toutes les méthodes du cycle de vie
  - [ ] Documentation détaillée

### 7.2 PluginContext
- [ ] **P0** Créer plugins/PluginContext.hpp
  - [ ] Pointeurs vers les managers
  - [ ] Configuration

### 7.3 PluginManager
- [ ] **P0** Créer plugins/PluginManager.hpp (Singleton)
  - [ ] Map des plugins
  - [ ] Gestion des bibliothèques dynamiques

- [ ] **P0** Implémenter plugins/PluginManager.cpp
  - [ ] loadPlugin(path) avec dlopen/LoadLibrary
  - [ ] unloadPlugin(name)
  - [ ] getPlugin(name)
  - [ ] updateAll(deltaTime)
  - [ ] renderAll(renderer)
  - [ ] scanPluginDirectory(path)

### 7.4 Système de Macros
- [ ] **P0** Créer des macros pour simplifier la création de plugins
```cpp
#define PLUGIN_EXPORT extern "C"
#define PLUGIN_CREATE(ClassName) \
    PLUGIN_EXPORT IPlugin* createPlugin() { \
        return new ClassName(); \
    }
```

### 7.5 Documentation Plugin
- [ ] **P0** Créer docs/plugin-development.md
  - [ ] Guide complet de création de plugin
  - [ ] Exemples de code
  - [ ] Best practices
  - [ ] API Reference

### 7.6 Tests
- [ ] **P1** Créer un plugin de test minimal
- [ ] **P1** Tester le chargement/déchargement
- [ ] **P1** Tester les erreurs (plugin invalide, etc.)

**Temps estimé Phase 7** : 2-3 semaines

---

## 🎬 Phase 8 : Premiers Plugins (Priorité MOYENNE)

### 8.1 ImageViewerPlugin
- [ ] **P0** Créer plugins/image-viewer/
- [ ] **P0** Implémenter ImageViewerPlugin.hpp/.cpp
  - [ ] Chargement d'image (PNG, JPEG)
  - [ ] Affichage
  - [ ] Zoom (molette souris)
  - [ ] Pan (drag avec souris)
  - [ ] Reset view

- [ ] **P1** Interface utilisateur
  - [ ] Barre d'outils
  - [ ] Indicateur de zoom
  - [ ] Minimap (optionnel)

- [ ] **P1** Tests et documentation

### 8.2 VideoPlayerPlugin
- [ ] **P0** Installer FFmpeg
- [ ] **P0** Créer plugins/video-player/
- [ ] **P0** Implémenter VideoPlayerPlugin.hpp/.cpp
  - [ ] Décodage vidéo avec FFmpeg
  - [ ] Lecture/Pause/Stop
  - [ ] Seek (barre de progression)
  - [ ] Contrôle du volume

- [ ] **P1** Interface de contrôle
  - [ ] Boutons play/pause/stop
  - [ ] Timeline
  - [ ] Volume slider

- [ ] **P2** Fonctionnalités avancées
  - [ ] Plein écran
  - [ ] Sous-titres
  - [ ] Playlist

### 8.3 TextEditorPlugin
- [ ] **P1** Créer plugins/text-editor/
- [ ] **P1** Fonctionnalités de base
  - [ ] Affichage de texte
  - [ ] Curseur clignotant
  - [ ] Saisie de texte
  - [ ] Sélection

- [ ] **P2** Fonctionnalités avancées
  - [ ] Copier/Coller
  - [ ] Undo/Redo
  - [ ] Rechercher/Remplacer
  - [ ] Coloration syntaxique

**Temps estimé Phase 8** : 4-6 semaines

---

## 🖥️ Phase 9 : Backends Additionnels (Priorité BASSE)

### 9.1 OpenGLRenderer
- [ ] **P1** Créer backends/OpenGLRenderer.hpp/.cpp
- [ ] **P1** Initialisation du contexte OpenGL
- [ ] **P1** Implémenter toutes les méthodes IRenderer
  - [ ] Utiliser des VBO/VAO
  - [ ] Shaders basiques (vertex/fragment)

- [ ] **P1** Support des textures OpenGL
- [ ] **P2** Optimisations (batch rendering)

### 9.2 MinilibXRenderer
- [ ] **P1** Créer backends/MinilibXRenderer.hpp/.cpp
- [ ] **P1** Adaptation pour École 42
  - [ ] Respect des contraintes MLX
  - [ ] Gestion des hooks MLX

- [ ] **P1** Tests sur machine 42

### 9.3 VulkanRenderer (Optionnel)
- [ ] **P2** Recherche et design
- [ ] **P2** Implémentation de base
- [ ] **P2** Tests de performance

**Temps estimé Phase 9** : 4-8 semaines

---

## 🧪 Phase 10 : Tests et Qualité (Priorité HAUTE)

### 10.1 Tests Unitaires
- [ ] **P0** Configurer framework de tests (Google Test)
- [ ] **P0** Tests pour classes utilitaires
  - [ ] Vec2
  - [ ] Color
  - [ ] Rect

- [ ] **P0** Tests pour EventManager
- [ ] **P0** Tests pour ResourceManager
- [ ] **P1** Tests pour PluginManager

### 10.2 Tests d'Intégration
- [ ] **P1** Test complet : Fenêtre + Widgets + Events
- [ ] **P1** Test : Chargement de plugin
- [ ] **P1** Test : Changement de backend au runtime

### 10.3 Tests de Performance
- [ ] **P1** Benchmark des backends
- [ ] **P1** Profiling (Valgrind, gprof)
- [ ] **P1** Optimisations

### 10.4 Outils de Qualité
- [ ] **P1** Configurer clang-format
- [ ] **P1** Configurer clang-tidy
- [ ] **P1** Vérification des fuites mémoire (Valgrind)
- [ ] **P2** Analyse statique (cppcheck)

**Temps estimé Phase 10** : 2-3 semaines

---

## 📚 Phase 11 : Documentation et Exemples (Priorité MOYENNE)

### 11.1 Documentation Technique
- [ ] **P0** Compléter docs/architecture.md
- [ ] **P0** Créer docs/api-reference.md
  - [ ] Toutes les classes publiques
  - [ ] Exemples pour chaque méthode

- [ ] **P1** docs/backend-implementation.md
  - [ ] Guide pour ajouter un nouveau backend

### 11.2 Tutoriels
- [ ] **P0** Tutorial 1 : Hello Window
- [ ] **P0** Tutorial 2 : Drawing Basics
- [ ] **P0** Tutorial 3 : Event Handling
- [ ] **P1** Tutorial 4 : Creating Your First Plugin
- [ ] **P1** Tutorial 5 : UI Widgets
- [ ] **P2** Tutorial 6 : Advanced Rendering

### 11.3 Exemples
- [ ] **P0** examples/basic-window/
- [ ] **P0** examples/draw-shapes/
- [ ] **P1** examples/custom-plugin/
- [ ] **P1** examples/ui-demo/
- [ ] **P2** examples/multi-backend/
- [ ] **P2** examples/game-demo/

### 11.4 Wiki
- [ ] **P1** Page d'accueil
- [ ] **P1** FAQ
- [ ] **P1** Troubleshooting
- [ ] **P2** Galerie de plugins communautaires

**Temps estimé Phase 11** : 3-4 semaines

---

## 🚀 Phase 12 : Release & Distribution (Priorité FINALE)

### 12.1 Préparation Release
- [ ] **P0** Versionning sémantique (1.0.0)
- [ ] **P0** CHANGELOG.md complet
- [ ] **P0** Release notes
- [ ] **P0** Vérification de toutes les dépendances

### 12.2 Packages
- [ ] **P1** Script d'installation Linux
- [ ] **P1** Homebrew formula (macOS)
- [ ] **P2** Package Windows (MSI)
- [ ] **P2** Snap/Flatpak

### 12.3 Distribution
- [ ] **P0** Tag Git v1.0.0
- [ ] **P0** Release GitHub avec binaires
- [ ] **P1** Site web du projet
  - [ ] Page d'accueil
  - [ ] Documentation en ligne
  - [ ] Blog

- [ ] **P2** Annonces
  - [ ] Reddit (r/cpp, r/gamedev)
  - [ ] Hacker News
  - [ ] Twitter/X

### 12.4 Communauté
- [ ] **P1** Créer Discord/Slack
- [ ] **P1** Forum de discussion
- [ ] **P2** Meetup/Présentation

**Temps estimé Phase 12** : 2 semaines

---

## 🔮 Phase 13 : Futures Fonctionnalités (Post v1.0)

### Priorité P1 (v1.1)
- [ ] Support 3D (OpenGL/Vulkan)
- [ ] Networking pour plugins
- [ ] Hot-reload des plugins
- [ ] Scripting (Lua/Python bindings)

### Priorité P2 (v1.2+)
- [ ] Editor visuel de layout
- [ ] Profiler intégré
- [ ] Asset pipeline
- [ ] Mobile support (Android/iOS)

### Plugins Communautaires
- [ ] Game Engine Plugin
- [ ] Data Visualization Plugin
- [ ] Music Player Plugin
- [ ] PDF Viewer Plugin
- [ ] Web Browser Plugin (WebKit)

---

## 📊 Métriques de Succès

### Qualité du Code
- [ ] Coverage de tests > 80%
- [ ] 0 warning avec `-Wall -Wextra -Werror`
- [ ] 0 fuite mémoire (Valgrind)
- [ ] Score Cppcheck > 90%

### Documentation
- [ ] Tous les headers documentés (Doxygen)
- [ ] 5+ tutoriels complets
- [ ] 10+ exemples fonctionnels
- [ ] Wiki avec 20+ pages

### Performance
- [ ] 60 FPS stable avec 100+ widgets
- [ ] Temps de chargement plugin < 100ms
- [ ] Utilisation mémoire < 100MB (idle)

### Communauté
- [ ] 100+ stars GitHub
- [ ] 10+ contributeurs
- [ ] 5+ plugins communautaires
- [ ] 50+ utilisateurs actifs

---

## 🎯 Priorités (Légende)

- **P0** : Critique - Bloquant pour la suite
- **P1** : Haute - Important pour v1.0
- **P2** : Moyenne - Nice to have
- **P3** : Basse - Post v1.0

---

## ⏱️ Estimation Totale

**Minimum (développement intensif)** : 6-9 mois  
**Réaliste (développement régulier)** : 12-18 mois  
**Avec imprévus** : 18-24 mois

---

## 📝 Notes

### Dépendances entre phases
- Phase 2 doit être terminée avant Phase 3
- Phase 4 est indépendante mais recommandée avant Phase 5
- Phase 7 nécessite Phases 2-6 complètes
- Phase 8 nécessite Phase 7

### Conseils
1. **Ne pas tout faire d'un coup** : Commencer petit (MVP)
2. **Tester en continu** : Ne pas accumuler la dette technique
3. **Documenter au fur et à mesure** : Plus facile que de le faire après
4. **Demander des reviews** : Partager le code tôt et souvent

### Jalons Importants
- ✅ **Milestone 1** : Fenêtre qui s'affiche (Phase 2-3)
- ✅ **Milestone 2** : Premier widget interactif (Phase 5)
- ✅ **Milestone 3** : Premier plugin fonctionnel (Phase 7-8)
- ✅ **Milestone 4** : Version 1.0 Release (Phase 12)

---

**Date de création** : Décembre 2024  
**Dernière mise à jour** : [À mettre à jour régulièrement]  
**Status** : 🔴 En planification