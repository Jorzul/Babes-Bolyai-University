class Ingredient:
    def __init__(self, id, name):
        """
        How do we protect class fields from changes?

        C++/Java/C# -> private (just inside the class)
                        protected (inside the class and derived classes)
                        public (everywhere)
                        default (Java), internal (C#)

        Python
            public       -> <name> (e.g., class.field_name)
            protected    -> _<name> (e.g., class._field_name)
            private      -> __<name> (e.g., class.__field_name) -> Python name mangling

        """
        self.id = id
        self.name = name


ingr = Ingredient(100, "Random Ingredient")
flour = Ingredient(101, "Flour")
ingr.x = 123

print(ingr.__dict__)
print(flour.__dict__)

data = list()

print(ingr.x)

print(ingr.id, ingr.name, ingr.x)
ingr.name = "Magical Ingredient"
print(ingr.id, ingr.name)

# print(flour.x)

print(type(ingr))
print(type(data))
