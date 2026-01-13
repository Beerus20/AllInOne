# Guide d'utilisation du JSON en C++

## Introduction

JSON (JavaScript Object Notation) est un format de données léger et facile à lire, très utilisé pour la configuration, l'échange de données et le stockage. Ce guide explique comment manipuler du JSON en C++.

---

## Bibliothèques JSON populaires en C++

### 1. **nlohmann/json** (Recommandée)
- Header-only (un seul fichier)
- API moderne et intuitive
- Très populaire et bien maintenue
- Syntaxe proche du JavaScript

### 2. **RapidJSON**
- Très rapide
- SAX et DOM API
- Plus complexe à utiliser

### 3. **jsoncpp**
- Bibliothèque plus ancienne
- API classique C++

**Pour ce guide, nous utiliserons nlohmann/json.**

---

## Installation de nlohmann/json

### Méthode 1 : Header-only (Recommandée)

Téléchargez le fichier unique :
```bash
cd include/
wget https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
```

Ou avec curl :
```bash
curl -o include/json.hpp https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
```

### Méthode 2 : Via gestionnaire de paquets

**Ubuntu/Debian :**
```bash
sudo apt-get install nlohmann-json3-dev
```

**macOS :**
```bash
brew install nlohmann-json
```

### Méthode 3 : Submodule Git
```bash
git submodule add https://github.com/nlohmann/json.git third_party/json
```

---

## Inclusion dans votre projet

### Dans vos fichiers C++

```cpp
#include <nlohmann/json.hpp>

// Alias pour simplifier l'utilisation
using json = nlohmann::json;
```

### Dans votre Makefile

```makefile
# Si vous utilisez la méthode header-only
INCLUDES = -I./include

# Si vous avez installé via gestionnaire de paquets
# (Généralement pas besoin de flags supplémentaires)
```

---

## Utilisation basique

### 1. Créer un objet JSON

```cpp
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
    // Méthode 1 : Construction directe
    json config = {
        {"width", 1920},
        {"height", 1080},
        {"fullscreen", false},
        {"title", "AllInOne Application"}
    };

    // Méthode 2 : Construction étape par étape
    json settings;
    settings["width"] = 1920;
    settings["height"] = 1080;
    settings["fullscreen"] = false;
    settings["title"] = "AllInOne Application";

    return 0;
}
```

### 2. Types de données supportés

```cpp
json data;

// Nombre entier
data["integer"] = 42;

// Nombre à virgule flottante
data["float"] = 3.14159;

// Booléen
data["boolean"] = true;

// Chaîne de caractères
data["string"] = "Hello, World!";

// Null
data["null_value"] = nullptr;

// Tableau
data["array"] = {1, 2, 3, 4, 5};

// Tableau avec différents types
data["mixed_array"] = {1, "two", 3.0, true};

// Objet imbriqué
data["nested"] = {
    {"key1", "value1"},
    {"key2", 42}
};
```

### 3. Lire des valeurs JSON

```cpp
json config = {
    {"width", 1920},
    {"height", 1080},
    {"renderer", "OpenGL"}
};

// Méthode 1 : Accès direct
int width = config["width"];
int height = config["height"];
std::string renderer = config["renderer"];

// Méthode 2 : Avec get<>()
int width = config["width"].get<int>();
std::string renderer = config["renderer"].get<std::string>();

// Méthode 3 : Avec valeur par défaut
int fps = config.value("fps", 60);  // Retourne 60 si "fps" n'existe pas
```

### 4. Vérifier l'existence d'une clé

```cpp
json config = {{"width", 1920}};

// Méthode 1 : contains()
if (config.contains("width")) {
    std::cout << "Width found: " << config["width"] << std::endl;
}

// Méthode 2 : find()
if (config.find("height") != config.end()) {
    std::cout << "Height found" << std::endl;
} else {
    std::cout << "Height not found" << std::endl;
}
```

---

## Lire et écrire des fichiers JSON

### 1. Charger depuis un fichier

```cpp
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

json loadConfig(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    
    json config;
    file >> config;
    return config;
}

// Utilisation
try {
    json config = loadConfig("assets/config/default-config.json");
    int width = config["width"];
    int height = config["height"];
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

### 2. Sauvegarder dans un fichier

```cpp
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

bool saveConfig(const json& config, const std::string& path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    
    // Méthode 1 : Écriture compacte
    file << config;
    
    // Méthode 2 : Écriture formatée (indentation de 4 espaces)
    file << config.dump(4);
    
    return true;
}

// Utilisation
json config = {
    {"width", 1920},
    {"height", 1080},
    {"renderer", "OpenGL"}
};

if (saveConfig(config, "config.json")) {
    std::cout << "Config saved!" << std::endl;
}
```

---

## Manipulation avancée

### 1. Tableaux JSON

```cpp
// Créer un tableau
json plugins = json::array();
plugins.push_back("ImageViewer");
plugins.push_back("Terminal");
plugins.push_back("VideoPlayer");

// Ou directement
json plugins = {"ImageViewer", "Terminal", "VideoPlayer"};

// Parcourir un tableau
for (const auto& plugin : plugins) {
    std::cout << plugin << std::endl;
}

// Accès par index
std::string first = plugins[0];

// Taille du tableau
size_t count = plugins.size();

// Vider un tableau
plugins.clear();
```

### 2. Objets imbriqués

```cpp
json config = {
    {"window", {
        {"width", 1920},
        {"height", 1080},
        {"title", "My App"}
    }},
    {"graphics", {
        {"renderer", "OpenGL"},
        {"vsync", true},
        {"msaa", 4}
    }}
};

// Accéder aux valeurs imbriquées
int width = config["window"]["width"];
std::string renderer = config["graphics"]["renderer"];

// Avec pointeur JSON (JSON Pointer)
int width = config["/window/width"_json_pointer];
```

### 3. Itérer sur un objet JSON

```cpp
json config = {
    {"width", 1920},
    {"height", 1080},
    {"fullscreen", false}
};

// Parcourir toutes les clés/valeurs
for (auto& [key, value] : config.items()) {
    std::cout << key << " = " << value << std::endl;
}

// Avec itérateurs
for (auto it = config.begin(); it != config.end(); ++it) {
    std::cout << it.key() << " = " << it.value() << std::endl;
}
```

### 4. Fusionner des objets JSON

```cpp
json config1 = {
    {"width", 1920},
    {"height", 1080}
};

json config2 = {
    {"fullscreen", true},
    {"vsync", false}
};

// Fusion (config1 est modifié)
config1.merge_patch(config2);

// Résultat :
// {
//   "width": 1920,
//   "height": 1080,
//   "fullscreen": true,
//   "vsync": false
// }

// Alternative : update()
config1.update(config2);
```

---

## Conversion entre JSON et structures C++

### 1. Convertir une structure en JSON

```cpp
#include <nlohmann/json.hpp>

struct Config {
    int width;
    int height;
    std::string renderer;
    bool fullscreen;
};

// Définir la fonction de conversion
void to_json(json& j, const Config& c) {
    j = json{
        {"width", c.width},
        {"height", c.height},
        {"renderer", c.renderer},
        {"fullscreen", c.fullscreen}
    };
}

// Définir la fonction de conversion inverse
void from_json(const json& j, Config& c) {
    j.at("width").get_to(c.width);
    j.at("height").get_to(c.height);
    j.at("renderer").get_to(c.renderer);
    j.at("fullscreen").get_to(c.fullscreen);
}

// Utilisation
Config config = {1920, 1080, "OpenGL", false};
json j = config;  // Conversion automatique vers JSON

Config loaded_config = j;  // Conversion automatique depuis JSON
```

### 2. Macro NLOHMANN_DEFINE_TYPE (Plus simple)

```cpp
#include <nlohmann/json.hpp>

struct Config {
    int width;
    int height;
    std::string renderer;
    bool fullscreen;
};

// Une seule ligne pour définir les conversions !
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Config, width, height, renderer, fullscreen)

// Utilisation
Config config = {1920, 1080, "OpenGL", false};
json j = config;

Config loaded = j.get<Config>();
```

---

## Gestion des erreurs

### 1. Vérification des types

```cpp
json data = {
    {"count", 42},
    {"name", "Test"}
};

// Vérifier le type avant l'accès
if (data["count"].is_number()) {
    int count = data["count"];
}

if (data["name"].is_string()) {
    std::string name = data["name"];
}

// Types disponibles :
// is_null(), is_boolean(), is_number(), is_number_integer()
// is_number_float(), is_string(), is_array(), is_object()
```

### 2. Gestion des exceptions

```cpp
#include <nlohmann/json.hpp>
using json = nlohmann::json;

try {
    json config;
    std::ifstream file("config.json");
    file >> config;
    
    // at() lance une exception si la clé n'existe pas
    int width = config.at("width");
    
} catch (const json::parse_error& e) {
    std::cerr << "Parse error: " << e.what() << std::endl;
} catch (const json::type_error& e) {
    std::cerr << "Type error: " << e.what() << std::endl;
} catch (const json::out_of_range& e) {
    std::cerr << "Key not found: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

---

## Exemple complet : Classe Config

```cpp
#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Config {
private:
    json m_data;
    std::string m_filepath;

public:
    Config() = default;

    // Charger depuis un fichier
    bool load(const std::string& path) {
        m_filepath = path;
        try {
            std::ifstream file(path);
            if (!file.is_open()) {
                std::cerr << "Cannot open config file: " << path << std::endl;
                return false;
            }
            file >> m_data;
            return true;
        } catch (const json::parse_error& e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
            return false;
        }
    }

    // Sauvegarder dans un fichier
    bool save() const {
        return save(m_filepath);
    }

    bool save(const std::string& path) const {
        try {
            std::ofstream file(path);
            if (!file.is_open()) {
                return false;
            }
            file << m_data.dump(4);
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error saving config: " << e.what() << std::endl;
            return false;
        }
    }

    // Obtenir une valeur avec valeur par défaut
    template<typename T>
    T get(const std::string& key, const T& defaultValue) const {
        return m_data.value(key, defaultValue);
    }

    // Définir une valeur
    template<typename T>
    void set(const std::string& key, const T& value) {
        m_data[key] = value;
    }

    // Vérifier si une clé existe
    bool has(const std::string& key) const {
        return m_data.contains(key);
    }

    // Obtenir le JSON brut
    const json& getData() const {
        return m_data;
    }

    // Afficher la configuration
    void print() const {
        std::cout << m_data.dump(4) << std::endl;
    }
};
```

### Utilisation de la classe Config

```cpp
#include "Config.hpp"

int main() {
    Config config;
    
    // Charger la configuration
    if (!config.load("assets/config/default-config.json")) {
        // Créer une configuration par défaut
        config.set("width", 1920);
        config.set("height", 1080);
        config.set("fullscreen", false);
        config.set("renderer", "OpenGL");
        config.set("vsync", true);
        config.save("assets/config/default-config.json");
    }
    
    // Lire les valeurs
    int width = config.get("width", 800);
    int height = config.get("height", 600);
    std::string renderer = config.get<std::string>("renderer", "SDL");
    
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Renderer: " << renderer << std::endl;
    
    // Modifier une valeur
    config.set("width", 2560);
    config.set("height", 1440);
    
    // Sauvegarder
    config.save();
    
    // Afficher toute la configuration
    config.print();
    
    return 0;
}
```

---

## Exemple de fichier JSON pour AllInOne

### assets/config/default-config.json

```json
{
  "window": {
    "width": 1920,
    "height": 1080,
    "title": "AllInOne Application",
    "fullscreen": false,
    "resizable": true
  },
  "graphics": {
    "renderer": "OpenGL",
    "vsync": true,
    "msaa": 4,
    "anisotropic_filtering": 16
  },
  "plugins": {
    "enabled": ["ImageViewer", "Terminal"],
    "disabled": ["VideoPlayer"],
    "paths": [
      "plugins/image-viewer/ImageViewerPlugin.so",
      "plugins/terminal/TerminalPlugin.so"
    ]
  },
  "resources": {
    "texture_path": "assets/textures/",
    "font_path": "assets/fonts/",
    "cache_size_mb": 512
  },
  "logging": {
    "level": "info",
    "file": "logs/application.log",
    "console": true
  }
}
```

---

## Astuces et bonnes pratiques

### 1. Utiliser des alias de type

```cpp
using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;  // Préserve l'ordre des clés
```

### 2. Formater l'output JSON

```cpp
json data = {{"a", 1}, {"b", 2}};

// Compact (une ligne)
std::string compact = data.dump();
// {"a":1,"b":2}

// Formaté avec indentation
std::string pretty = data.dump(4);
// {
//     "a": 1,
//     "b": 2
// }

// Avec indentation personnalisée
std::string custom = data.dump(2, ' ', false, json::error_handler_t::replace);
```

### 3. Parser du JSON depuis une string

```cpp
std::string jsonStr = R"(
{
    "width": 1920,
    "height": 1080,
    "fullscreen": false
}
)";

json config = json::parse(jsonStr);

// Avec gestion d'erreurs
try {
    json config = json::parse(jsonStr);
} catch (const json::parse_error& e) {
    std::cerr << "Parse error at byte " << e.byte << std::endl;
}
```

### 4. Valider le JSON

```cpp
#include <nlohmann/json.hpp>

bool isValidConfig(const json& config) {
    // Vérifier les champs obligatoires
    if (!config.contains("width") || !config.contains("height")) {
        return false;
    }
    
    // Vérifier les types
    if (!config["width"].is_number_integer() || 
        !config["height"].is_number_integer()) {
        return false;
    }
    
    // Vérifier les valeurs
    if (config["width"] <= 0 || config["height"] <= 0) {
        return false;
    }
    
    return true;
}
```

### 5. Merge de configurations

```cpp
// Configuration par défaut
json defaultConfig = {
    {"width", 800},
    {"height", 600},
    {"fullscreen", false},
    {"vsync", true}
};

// Configuration utilisateur (peut être partielle)
json userConfig = {
    {"width", 1920},
    {"height", 1080}
};

// Fusionner (userConfig écrase defaultConfig)
defaultConfig.merge_patch(userConfig);

// Résultat :
// {
//   "width": 1920,      // Écrasé
//   "height": 1080,     // Écrasé
//   "fullscreen": false, // Conservé
//   "vsync": true       // Conservé
// }
```

---

## Performance et optimisation

### 1. Réserver de l'espace pour les tableaux

```cpp
json array = json::array();
array.get_ref<json::array_t&>().reserve(1000);

for (int i = 0; i < 1000; ++i) {
    array.push_back(i);
}
```

### 2. Déplacer au lieu de copier

```cpp
json createLargeConfig() {
    json config;
    // ... remplir config ...
    return config;  // Optimisation RVO (Return Value Optimization)
}

json config = createLargeConfig();  // Pas de copie grâce au move semantics
```

### 3. Utiliser des références

```cpp
void processConfig(const json& config) {  // Par référence constante
    // Lecture seulement
}

void modifyConfig(json& config) {  // Par référence
    config["modified"] = true;
}
```

---

## Résumé des opérations courantes

| Opération | Code |
|-----------|------|
| Créer un objet | `json obj = {{"key", "value"}};` |
| Créer un tableau | `json arr = {1, 2, 3};` |
| Ajouter une clé | `obj["key"] = value;` |
| Lire une valeur | `auto val = obj["key"];` |
| Vérifier existence | `obj.contains("key")` |
| Lire depuis fichier | `std::ifstream f("file.json"); json j; f >> j;` |
| Écrire vers fichier | `std::ofstream f("file.json"); f << j.dump(4);` |
| Parser string | `json j = json::parse(str);` |
| Convertir en string | `std::string s = j.dump();` |
| Itérer | `for (auto& [k, v] : j.items()) {...}` |
| Taille | `j.size()` |
| Vider | `j.clear()` |

---

## Compilation

### Commande de compilation

```bash
# Avec g++
g++ -std=c++17 -I./include main.cpp -o app

# Avec c++
c++ -std=c++17 -I./include main.cpp -o app
```

### Dans le Makefile du projet

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
INCLUDES = -I./include

# nlohmann/json est header-only, pas besoin de linker
```

---

## Ressources supplémentaires

- **Documentation officielle** : https://json.nlohmann.me/
- **GitHub** : https://github.com/nlohmann/json
- **Exemples** : https://json.nlohmann.me/features/
- **Playground en ligne** : https://wandbox.org/

---

## Conclusion

La bibliothèque nlohmann/json offre une API moderne et intuitive pour manipuler du JSON en C++. Elle est :
- ✅ **Facile à utiliser** : Syntaxe proche du JavaScript
- ✅ **Header-only** : Pas de compilation supplémentaire
- ✅ **Type-safe** : Détection d'erreurs à la compilation
- ✅ **Performante** : Optimisée pour la vitesse
- ✅ **Bien documentée** : Documentation exhaustive et exemples

Pour le projet AllInOne, elle est idéale pour gérer les fichiers de configuration, sauvegarder les états et échanger des données avec les plugins.
