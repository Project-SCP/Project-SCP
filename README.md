# 📦 Project SCP: A Modular, Open Source SCP Game Platform

[![GitHub Stars](https://img.shields.io/github/stars/TheFantasticLoki/project-scp.svg?style=flat-square)](https://github.com/TheFantasticLoki/project-scp/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/TheFantasticLoki/project-scp.svg?style=flat-square)](https://github.com/TheFantasticLoki/project-scp/network/members)
[![Contributors](https://img.shields.io/github/contributors/TheFantasticLoki/project-scp.svg?style=flat-square)](https://github.com/TheFantasticLoki/project-scp/graphs/contributors)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

---

## 🚨 What is Project SCP?

**Project SCP** is an open-source, Unreal Engine-powered reimagining of **SCP: Containment Breach** designed not just as a game — but as a *platform*. Our mission is to provide a modern, high-performance foundation where:

* 🔁 **Classic SCP game modes** like Containment Breach can be recreated with fidelity and flair
* 🧩 **Community-created content** like new SCPs, rooms, and endings can be added seamlessly
* 🌐 **Workshop integration** allows sharing, downloading, and even monetizing mods
* 💡 **Developers and modders** can build entire SCP games using our framework

This is not just a remake — it is the **GMod of SCP**. Built from the ground up for extensibility, creativity, and long-term support.

---

## 🧱 Key Features

### 🎮 Core Game Modes

* Built-in support for **Containment Breach-style progression**
* Multiple endings, narrative branching, SCP interactions
* Modular gameplay systems for blinking, stamina, inventory, etc.

### 🗺️ Modular Map System

* Rooms are built as individual prefabs/blueprints
* Levels can be **procedurally generated** or manually authored
* Room metadata supports conditions (e.g. "needs keycard level 3")

### 👁️ Modern Rendering

* Built with **Unreal Engine 5** for high-fidelity visuals
* Lumen lighting, Nanite geometry, modern post-processing
* Supports both high-end and optimized low-end setups

### 🔌 Modding First

* Mods are distributed as `.pak` files
* Mod types include:

  * 📦 SCPs (logic + models + behavior)
  * 🏗️ Rooms
  * 🧠 Entire game modes
  * 🎬 Cutscenes or audio logs
* Mod-friendly architecture: plug-and-play Blueprint or C++ components

### 🛠️ Developer Tools

* In-editor content creation tools
* Sample content packs
* Hooks and APIs for AI, triggers, audio, doors, and more

### 🧵 Steam Workshop Support *(Planned)*

* Download, rate, and auto-update mods
* Allow full-game conversions as Workshop entries
* Optional: monetizable DLC-style mod support

---

## 💡 Why Build This?

SCP: Containment Breach, built in Blitz3D, was groundbreaking — but constrained by its engine. Rather than continuing to patch legacy tech, **Project SCP aims to elevate the concept using modern tools**, and do so *in the open*.

We want a future where:

* Developers can make their own SCP games faster
* Modders can publish Workshop-ready content without touching C++
* Players can discover entire SCP experiences in a single install

---

## 🌍 Vision Statement

Project SCP isn’t just one game. It’s the **platform** where any SCP horror, sandbox, simulation, or narrative experience can be hosted and shared —

> Think of it as *Garry’s Mod meets SCP Foundation*, powered by Unreal.

We aim to eventually support **remakes or reinterpretations** of *SCP: Unity*, *SCP: Secret Laboratory*, *SCP: Blackout*, and more — all within a single extensible environment.

---

## 🚧 Current Status

> 💬 We are currently in the **design and architecture phase**.

The repository currently includes design documents and architectural planning. Contributors are welcome to:

* Suggest features
* Share modular blueprints
* Begin prototyping systems (SCPs, UI, Inventory, Room Templates)

---

## 🤝 Contributing

Contributions are welcome and encouraged! We’re structuring this project so that contributions happen via Pull Requests and Issue discussions.

### 📁 Coming Soon:

* `CONTRIBUTING.md`: Guidelines for contributing code/content
* `CODE_OF_CONDUCT.md`: Community standards
* `docs/`: Folder containing design plans and technical breakdowns

### 🧪 Areas Open for Contribution:

* Room spawning system
* Basic SCP AI (173, 106, 049)
* Modular inventory/interaction system
* Level streaming and blueprint API
* Save/load and progression state

---

## 📜 License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute it — even commercially — with proper attribution.

Unreal Engine source is governed by Epic Games' [Unreal Engine EULA](https://www.unrealengine.com/en-US/eula). Do not distribute UE source code or non-redistributable engine binaries.

---

## 📣 Join the Foundation

We’ll be looking to grow our contributor base and community over time. Want to build the future of SCP horror games together?

📌 Star ⭐ the repo, fork 🍴 it, and join us!

---

> 🧬 *Secure. Contain. Platform.*
