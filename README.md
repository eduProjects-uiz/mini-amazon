

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

💡 Conseils d'utilisation sous Windows
L'application utilise l'encodage standard UTF-8 pour afficher des icônes et émojis expressifs (🛒, 💻, 👕, 🍳). Les anciennes versions de l'invite de commandes Windows (cmd.exe) affichent parfois ces caractères sous forme de rectangles ou de points d'interrogation.
Pour une expérience visuelle optimale, il est vivement conseillé d'exécuter l'application au sein de la nouvelle application Windows Terminal ou de PowerShell.


---



---


**Copyright © 2026**

Project realized by **MONCIF ZOUHAIR** - **ISRISS KABEL** - **BRAHIM	AIT OUBRAIM** - **SABIR	AIT BADDI** .
</>  Faculté Polydisciplinaire de Taroudant. ([uiz.ac.ma][1])

[1]: https://www.uiz.ac.ma/faculte-polydisciplinaire-taroudant?utm_source=chatgpt.com "Faculté Polydisciplinaire - Taroudant | Université Ibn Zohr"




