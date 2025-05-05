{
  inputs = {
    arduino-nix.url = "github:bouk/arduino-nix";
    arduino-index = {
      url = "github:bouk/arduino-indexes";
      flake = false;
    };
  };

  outputs = {
    nixpkgs,
    arduino-nix,
    arduino-index,
    ...
  }:
  let
    inherit (nixpkgs) lib;

    forAllSystems = lib.genAttrs nixpkgs.legacyPackages.aarch64-darwin.arduino-cli.meta.platforms;

    overlays = [
      (arduino-nix.overlay)
      (arduino-nix.mkArduinoPackageOverlay (arduino-index + "/index/package_index.json"))
      (arduino-nix.mkArduinoPackageOverlay (arduino-index + "/index/package_keyboardio_index.json"))
      (arduino-nix.mkArduinoLibraryOverlay (arduino-index + "/index/library_index.json"))
    ];

    importPkgs = system: (import nixpkgs) { inherit system overlays; };

    arduinoCLI = (pkgs: pkgs.wrapArduinoCLI {
      packages = with pkgs.arduinoPackages; [
        platforms.keyboardio.avr."1.99.9"
        platforms.keyboardio.gd32."1.99.9"
      ];
    });

  in
    {
      devShells = (forAllSystems (system:
        let
          pkgs = importPkgs system;
        in
          {
            default = pkgs.mkShell {
              packages = [(arduinoCLI pkgs)];
            };
          }));
    };
}
