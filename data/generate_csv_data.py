import pandas as pd

book_name_words = pd.read_csv("book_name_words.dat", header=None, names=["Word"])
book_name_words = book_name_words["Word"].tolist()

last_names = pd.read_csv("last_names.dat", header=None, names=["Last Name"])
last_names = last_names["Last Name"].tolist()

first_names = pd.read_csv("first_names.dat", header=None, names=["First Name"])
first_names = first_names["First Name"].tolist()

book_types = pd.read_csv("book_types.dat", header=None, names=["Book Type"])
book_types = book_types["Book Type"].tolist()

publishers_names = pd.read_csv("publishers.dat", header=None, names=["Publisher"])
publishers_names = publishers_names["Publisher"].tolist()


languages = pd.read_csv("languages.dat", header=None, names=["Language"])
languages = languages["Language"].tolist()


import random
import pandas as pd
from datetime import datetime, timedelta


def random_date(start, end):
    start_date = datetime.strptime(start, "%Y-%m-%d")
    end_date = datetime.strptime(end, "%Y-%m-%d")
    delta = end_date - start_date
    random_days = random.randint(0, delta.days)
    return (start_date + timedelta(days=random_days)).strftime("%Y-%m-%d")


def generate_books_csv(n):
    books_data = [
        {
            "book_id": i + 1,
            "name": " ".join(
                random.sample(
                    book_name_words,
                    k=random.randint(2, 3),
                )
            ),
            "author": f"{random.choice(first_names)} {random.choice(last_names)}",
            "publish": random.choice(publishers_names),
            "ISBN": f"{random.randint(1000000000, 9999999999)}",
            "language": random.choice(languages),
            "price": round(random.uniform(10, 200), 2),
            "pub_date": random_date("1900-01-01", "2025-01-01"),
            "class": random.choice(book_types),
            "quantity": random.randint(1, 20),
        }
        for i in range(1, n + 1)
    ]
    df = pd.DataFrame(books_data)
    df.to_csv("books.csv", index=False)


def generate_users_csv(n):
    users_data = [
        {
            "user_id": i + 1,
            "username": random.choice(first_names) + random.choice(last_names),
            "password": "password",
            "role": random.choice(["admin", "user"]),
        }
        for i in range(n)
    ]
    df = pd.DataFrame(users_data)
    df.to_csv("users.csv", index=False)


def generate_rentals_csv(n):
    rentals_data = [
        {
            "rental_id": i + 1,
            "book_id": random.randint(1, n),
            "user_id": random.randint(1, n),
            "rent_date": random_date("1900-01-01", "2025-01-01"),
            "return_date": random_date("1900-01-01", "2025-01-01"),
        }
        for i in range(n)
    ]
    df = pd.DataFrame(rentals_data)
    df.to_csv("rentals.csv", index=False)


generate_books_csv(100)
generate_users_csv(100)
generate_rentals_csv(100)
