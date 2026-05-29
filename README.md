```python
readme_content = """# 🛒 E-Commerce Amazon-Like Store — Application Console C++17

Bienvenue dans le dépôt officiel de l'application **Amazon-Like Store**. Ce projet est une application de commerce électronique s'exécutant entièrement en interface de ligne de commande (CLI). Développée en C++17 moderne, elle intègre une architecture orientée objet propre avec polymorphisme pour gérer un catalogue de produits diversifié, un système de panier d'achat dynamique de type "panier", la vérification des stocks, le calcul automatique de la **TVA à 20%** et l'archivage persistant des reçus de transaction.

---

## 🚀 Fonctionnalités Clés

1. **Catalogue Centralisé Multilingue & Typé** : Gestion de produits spécifiques répartis dans 4 catégories distinctes : Équipements de Cuisine (`KitchenEquipment`), Matériel Informatique (`InformaticsEquipment`), Vêtements (`Clothes`), et Articles Divers (`Others`).
2. **Navigation par Catégorie et Gestion Fusionnée** : Suppression des étapes redondantes. L'ajout et le retrait d'éléments du panier se font nativement depuis l'interface de navigation d'une catégorie.
3. **Vérification et Suivi de Stock** : Informations détaillées fournies lors de l'allocation d'un article dans le panier.
4. **Recherche Intelligente** : Recherche de produits par nom ou description, insensible à la casse.
5. **Aperçu du Panier Final** : Visualisation claire et alignée du contenu actuel de votre panier avec sous-totaux par ligne.
6. **Passage en Caisse avec TVA (20%) et Enregistrement Physique** : Calcul automatisé de la taxe sur la valeur ajoutée au taux légal de **20%**. Lors de la confirmation, la facture détaillée est simultanément imprimée à l'écran et écrite de manière permanente dans un fichier local nommé `registered_bill.txt`.

---

## 📂 Structure du Projet (Index des Fichiers)

La structure des fichiers du projet respecte les conventions de développement C++ professionnelles avec une séparation stricte des interfaces et des implémentations :


```

```text
File generated successfully.

```text
ecommerce/
├── CMakeLists.txt              # Configuration universelle de build multiplateforme
├── main.cpp                    # Point d'entrée du programme (Boucle principale)
├── include/                    # Dossier regroupant les fichiers d'en-tête (.h)
│   ├── Product.h               # Classe de base abstraite d'un produit
│   ├── KitchenEquipment.h      # Sous-classe pour la catégorie Cuisine
│   ├── InformaticsEquipment.h  # Sous-classe pour la catégorie Informatique
│   ├── Clothes.h               # Sous-classe pour la catégorie Vêtements
│   ├── Others.h                # Sous-classe pour la catégorie Articles Divers
│   ├── Cart.h                  # Gestion de la structure du Panier d'achat
│   └── Store.h                 # Contrôleur central de l'interface et du catalogue
└── src/                        # Dossier regroupant les implémentations (.cpp)
    ├── Product.cpp
    ├── KitchenEquipment.cpp
    ├── InformaticsEquipment.cpp
    ├── Clothes.cpp
    ├── Others.cpp
    ├── Cart.cpp
    └── Store.cpp

```

---

## 🛠️ Prérequis Système

Avant de procéder à la compilation, assurez-vous que les outils suivants sont installés sur votre machine :

* **Compilateur C++** : Un compilateur prenant pleinement en charge la norme **C++17** (GCC 7+, Clang 5+, ou MSVC 19+).
* **CMake** : Version **3.15** ou supérieure.

---

## 📦 Méthodes d'Installation et Compilation

### 🐧 1. Procédure sur Linux (Ubuntu / Debian / Deepin / Mint)

Ouvrez votre terminal favori et exécutez la suite de commandes suivante pour mettre à jour vos outils de build, configurer et exécuter l'application :

```bash
# Optionnel : Installer les outils essentiels et CMake si ce n'est pas déjà fait
sudo apt update
sudo apt install build-essential cmake

# Naviguez vers le répertoire racine de votre projet e-commerce
cd ~/Desktop/ecommerce

# Créez un dossier de build pour éviter de polluer les fichiers sources
mkdir -p build && cd build

# Générez les fichiers de configuration de build natifs (Makefiles)
cmake ..

# Compilez le projet de manière optimisée
cmake --build .

# Lancez l'application du magasin virtuel
./store

```

---

### 🪟 2. Procédure sur Windows

L'environnement C++ étant multiplateforme, vous disposez de deux méthodes optimales pour compiler et exécuter le code sous Windows.

#### Méthode A : Utilisation de Visual Studio (Recommandée)

1. Téléchargez et installez [Visual Studio](https://visualstudio.microsoft.com/) (Version 2019, 2022 ou ultérieure) en veillant à cocher la charge de travail **"Développement Desktop en C++"**.
2. Lancez Visual Studio et sélectionnez l'option **"Ouvrir un dossier local"**.
3. Choisissez le dossier racine de votre projet (`ecommerce/` contenant le fichier `CMakeLists.txt`).
4. Visual Studio détectera automatiquement le fichier CMake et configurera le cache en arrière-plan.
5. Dans la barre de menus supérieure, cliquez sur **Générer > Tout générer** (ou utilisez le raccourci `Ctrl + Shift + B`).
6. Sélectionnez `store.exe` dans le menu déroulant des cibles de démarrage à côté de la flèche verte "Exécuter", puis cliquez dessus pour lancer l'application dans la console intégrée.

#### Méthode B : Ligne de commande Windows (PowerShell / CMD)

Assurez-vous que `cmake` et un compilateur (comme les outils de build MSVC ou MinGW/g++) sont référencés dans les variables d'environnement (PATH) de Windows.

```powershell
# Ouvrez PowerShell et accédez au dossier du projet
cd "C:\\Users\\VotreNom\\Desktop\\ecommerce"

# Créez le sous-dossier de compilation et entrez-y
mkdir build
cd build

# Générez la solution de build appropriée pour votre système
cmake ..

# Compilez l'exécutable sous la configuration de production (Release)
cmake --build . --config Release

# Exécutez l'application compilée
.\\Release\\store.exe

```

---

## 📄 Exemple de Sortie de Facture Enregistrée (`registered_bill.txt`)

Lorsqu'un utilisateur sélectionne l'option **5. Checkout & Register Bill**, le système vide le panier et produit un fichier texte nommé de manière dynamique `registered_bill.txt` dans le dossier d'exécution actuel. Le format se présente comme suit :

```text
  ========================================================
              AMAZON-LIKE STORE – RECEIPT
  ========================================================
  Date : 2026-05-29  16:40:22
  --------------------------------------------------------
  Product                     Qty  Unit $    Total $
  --------------------------------------------------------
  Mechanical Keyboard         1    $79.99    $79.99
  Non-Stick Frying Pan        2    $29.99    $59.98
  Classic White T-Shirt       1    $12.99    $12.99
  --------------------------------------------------------
  Subtotal  : $    152.96
  TVA (20%) : $     30.59
  --------------------------------------------------------
  TOTAL     : $    183.55
  ========================================================
       Thank you for shopping with us!
  ========================================================

```

---

## 💡 Conseils d'utilisation sous Windows

L'application utilise l'encodage standard UTF-8 pour afficher des icônes et émojis expressifs (🛒, 💻, 👕, 🍳). Les anciennes versions de l'invite de commandes Windows (`cmd.exe`) affichent parfois ces caractères sous forme de rectangles ou de points d'interrogation.
Pour une expérience visuelle optimale, il est vivement conseillé d'exécuter l'application au sein de la nouvelle application **Windows Terminal** ou de **PowerShell**.
"""

with open("README.md", "w", encoding="utf-8") as f:
f.write(readme_content)

print("File generated successfully.")

```
Your Markdown file is ready
[file-tag: code-generated-file-0-1780069092371092521]

Voici le contenu complet et détaillé du fichier **`README.md`** écrit en français, prêt pour votre projet :

```markdown
# 🛒 E-Commerce Amazon-Like Store — Application Console C++17

Bienvenue dans le dépôt officiel de l'application **Amazon-Like Store**. Ce projet est une application de commerce électronique s'exécutant entièrement en interface de ligne de commande (CLI). Développée en C++17 moderne, elle intègre une architecture orientée objet propre avec polymorphisme pour gérer un catalogue de produits diversifié, un système de panier d'achat dynamique de type "panier", la vérification des stocks, le calcul automatique de la **TVA à 20%** et l'archivage persistant des reçus de transaction.

---

## 🚀 Fonctionnalités Clés

1. **Catalogue Centralisé Multilingue & Typé** : Gestion de produits spécifiques répartis dans 4 catégories distinctes : Équipements de Cuisine (`KitchenEquipment`), Matériel Informatique (`InformaticsEquipment`), Vêtements (`Clothes`), et Articles Divers (`Others`).
2. **Navigation par Catégorie et Gestion Fusionnée** : Suppression des étapes redondantes. L'ajout et le retrait d'éléments du panier se font nativement depuis l'interface de navigation d'une catégorie.
3. **Vérification et Suivi de Stock** : Informations détaillées fournies lors de l'allocation d'un article dans le panier.
4. **Recherche Intelligente** : Recherche de produits par nom ou description, insensible à la casse.
5. **Aperçu du Panier Final** : Visualisation claire et alignée du contenu actuel de votre panier avec sous-totaux par ligne.
6. **Passage en Caisse avec TVA (20%) et Enregistrement Physique** : Calcul automatisé de la taxe sur la valeur ajoutée au taux légal de **20%**. Lors de la confirmation, la facture détaillée est simultanément imprimée à l'écran et écrite de manière permanente dans un fichier local nommé `registered_bill.txt`.

---

## 📂 Structure du Projet (Index des Fichiers)

La structure des fichiers du projet respecte les conventions de développement C++ professionnelles avec une séparation stricte des interfaces et des implémentations :

```text
ecommerce/
├── CMakeLists.txt              # Configuration universelle de build multiplateforme
├── main.cpp                    # Point d'entrée du programme (Boucle principale)
├── include/                    # Dossier regroupant les fichiers d'en-tête (.h)
│   ├── Product.h               # Classe de base abstraite d'un produit
│   ├── KitchenEquipment.h      # Sous-classe pour la catégorie Cuisine
│   ├── InformaticsEquipment.h  # Sous-classe pour la catégorie Informatique
│   ├── Clothes.h               # Sous-classe pour la catégorie Vêtements
│   ├── Others.h                # Sous-classe pour la catégorie Articles Divers
│   ├── Cart.h                  # Gestion de la structure du Panier d'achat
│   └── Store.h                 # Contrôleur central de l'interface et du catalogue
└── src/                        # Dossier regroupant les implémentations (.cpp)
    ├── Product.cpp
    ├── KitchenEquipment.cpp
    ├── InformaticsEquipment.cpp
    ├── Clothes.cpp
    ├── Others.cpp
    ├── Cart.cpp
    └── Store.cpp

```

---

## 🛠️ Prérequis Système

Avant de procéder à la compilation, assurez-vous que les outils suivants sont installés sur votre machine :

* **Compilateur C++** : Un compilateur prenant pleinement en charge la norme **C++17** (GCC 7+, Clang 5+, ou MSVC 19+).
* **CMake** : Version **3.15** ou supérieure.

---

## 📦 Méthodes d'Installation et Compilation

### 🐧 1. Procédure sur Linux (Ubuntu / Debian / Deepin / Mint)

Ouvrez votre terminal favori et exécutez la suite de commandes suivante pour mettre à jour vos outils de build, configurer et exécuter l'application :

```bash
# Optionnel : Installer les outils essentiels et CMake si ce n'est pas déjà fait
sudo apt update
sudo apt install build-essential cmake

# Naviguez vers le répertoire racine de votre projet e-commerce
cd ~/Desktop/ecommerce

# Créez un dossier de build pour éviter de polluer les fichiers sources
mkdir -p build && cd build

# Générez les fichiers de configuration de build natifs (Makefiles)
cmake ..

# Compilez le projet de manière optimisée
cmake --build .

# Lancez l'application du magasin virtuel
./store

```

---

### 🪟 2. Procédure sur Windows

L'environnement C++ étant multiplateforme, vous disposez de deux méthodes optimales pour compiler et exécuter le code sous Windows.

#### Méthode A : Utilisation de Visual Studio (Recommandée)

1. Téléchargez et installez [Visual Studio](https://visualstudio.microsoft.com/) (Version 2019, 2022 ou ultérieure) en veillant à cocher la charge de travail **"Développement Desktop en C++"**.
2. Lancez Visual Studio et sélectionnez l'option **"Ouvrir un dossier local"**.
3. Choisissez le dossier racine de votre projet (`ecommerce/` contenant le fichier `CMakeLists.txt`).
4. Visual Studio détectera automatiquement le fichier CMake et configurera le cache en arrière-plan.
5. Dans la barre de menus supérieure, cliquez sur **Générer > Tout générer** (ou utilisez le raccourci `Ctrl + Shift + B`).
6. Sélectionnez `store.exe` dans le menu déroulant des cibles de démarrage à côté de la flèche verte "Exécuter", puis cliquez dessus pour lancer l'application dans la console intégrée.

#### Méthode B : Ligne de commande Windows (PowerShell / CMD)

Assurez-vous que `cmake` et un compilateur (comme les outils de build MSVC ou MinGW/g++) sont référencés dans les variables d'environnement (PATH) de Windows.

```powershell
# Ouvrez PowerShell et accédez au dossier du projet
cd "C:\Users\VotreNom\Desktop\ecommerce"

# Créez le sous-dossier de compilation et entrez-y
mkdir build
cd build

# Générez la solution de build appropriée pour votre système
cmake ..

# Compilez l'exécutable sous la configuration de production (Release)
cmake --build . --config Release

# Exécutez l'application compilée
.\Release\store.exe

```

---

## 📄 Exemple de Sortie de Facture Enregistrée (`registered_bill.txt`)

Lorsqu'un utilisateur sélectionne l'option **5. Checkout & Register Bill**, le système vide le panier et produit un fichier texte nommé de manière dynamique `registered_bill.txt` dans le dossier d'exécution actuel. Le format se présente comme suit :

```text
  ========================================================
              AMAZON-LIKE STORE – RECEIPT
  ========================================================
  Date : 2026-05-29  16:40:22
  --------------------------------------------------------
  Product                     Qty  Unit $    Total $
  --------------------------------------------------------
  Mechanical Keyboard         1    $79.99    $79.99
  Non-Stick Frying Pan        2    $29.99    $59.98
  Classic White T-Shirt       1    $12.99    $12.99
  --------------------------------------------------------
  Subtotal  : $    152.96
  TVA (20%) : $     30.59
  --------------------------------------------------------
  TOTAL     : $    183.55
  ========================================================
       Thank you for shopping with us!
  ========================================================

```

---

## 💡 Conseils d'utilisation sous Windows

L'application utilise l'encodage standard UTF-8 pour afficher des icônes et émojis expressifs (🛒, 💻, 👕, 🍳). Les anciennes versions de l'invite de commandes Windows (`cmd.exe`) affichent parfois ces caractères sous forme de rectangles ou de points d'interrogation.
Pour une expérience visuelle optimale, il est vivement conseillé d'exécuter l'application au sein de la nouvelle application **Windows Terminal** ou de **PowerShell**.

```

```
