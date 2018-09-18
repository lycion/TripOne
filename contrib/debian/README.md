
Debian
====================
This directory contains files used to package triponed/tripone-qt
for Debian-based Linux systems. If you compile triponed/tripone-qt yourself, there are some useful files here.

## triponecash: URI support ##


tripone-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tripone-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tripone-qt binary to `/usr/bin`
and the `../../share/pixmaps/tripone128.png` to `/usr/share/pixmaps`

tripone-qt.protocol (KDE)

