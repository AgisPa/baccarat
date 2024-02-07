
---

# Baccarat Simulation

## Introduction

This is a C++ program that simulates a game of Baccarat according to the official rules of the game. Baccarat is a popular card game often played in casinos, where players bet on the outcome of two hands - the "player" and the "banker."

## Rules of Baccarat

In Baccarat, the objective is to get as close to a total of 9 points as possible. Face cards and 10s are worth 0 points, while all other cards are worth their face value. If the total value of a hand exceeds 9, only the second digit is used (e.g., a hand with a 7 and an 8 is worth 5 points, not 15).

The game proceeds as follows:

1. Both the player and the banker are dealt two cards each.
2. If either the player or the banker has a total of 8 or 9 points from the first two cards, they win the game automatically. This is called a "natural."
3. If neither the player nor the banker has a natural, the player may draw a third card according to a set of rules:
   - If the player's total is 0-5, they draw a third card.
   - If the player's total is 6 or 7, they stand.
4. After the player has finished drawing or standing, the banker follows a set of rules to determine whether to draw a third card:
   - If the banker's total is 0-2, they draw a third card.
   - If the banker's total is 3-6, they draw a third card based on the player's third card (if drawn).
   - If the banker's total is 7, they stand.
5. The hand with the highest total wins. If both hands have the same total, it's a tie.

## Example Output

```
Phand - Bhand - Outcome
A,3 - 3,5 - BANKER
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
