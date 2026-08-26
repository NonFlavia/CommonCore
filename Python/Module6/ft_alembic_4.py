import alchemy


def main() -> None:
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print("Testing create_air:", alchemy.create_air())
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    try:
        # errore intenzionale: create_earth non è esposta da alchemy
        earth = alchemy.create_earth()  # type: ignore[attr-defined]
        print("Testing the hidden create_earth:", earth)
    except AttributeError as error:
        print("Got expected exception:", error)


if __name__ == "__main__":
    main()
