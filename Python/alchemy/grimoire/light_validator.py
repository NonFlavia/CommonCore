from .light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    text = ingredients.lower()
    for allowed in light_spell_allowed_ingredients():
        if allowed in text:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
