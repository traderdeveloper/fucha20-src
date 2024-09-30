
Debian
====================
This directory contains files used to package FUCHAd/FUCHA-qt
for Debian-based Linux systems. If you compile FUCHAd/FUCHA-qt yourself, there are some useful files here.

## pivx: URI support ##


FUCHA-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install FUCHA-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your FUCHA-qt binary to `/usr/bin`
and the `../../share/pixmaps/pivx128.png` to `/usr/share/pixmaps`

FUCHA-qt.protocol (KDE)

