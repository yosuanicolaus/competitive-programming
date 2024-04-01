import bisect


def solve(project_line: list, virus_line: list) -> list:
    project_line.sort(key=lambda x: x[0])
    virus_line.sort(key=lambda x: x[0])
    virus_line_pos = [p for (p, _) in virus_line]

    for pos, pd in project_line[::-1]:
        start_idx = bisect.bisect_right(virus_line_pos, pos)

        for _, vd in virus_line[start_idx:]:
            if not vd["active"]:
                # virus already die
                continue

            project = pd["name"]
            if project in vd["target_projects"]:
                # start battle
                if vd["target_projects"][project] < pd["life"]:
                    # virus die
                    vd["active"] = False
                pd["life"] -= vd["target_projects"][project]

                if pd["life"] <= 0:
                    # project die
                    pd["life"] = 0
                    break

    survivor = []
    for _, pd in project_line[::-1]:
        if pd["life"] > 0:
            survivor.append(pd["name"])

    return survivor


def main():
    n, m, q = map(int, input().split())

    project_line = []
    virus_line = []

    for _ in range(n):
        project, life, pos = input().split()
        life, pos = int(life), int(pos)

        project_line.append(
            (
                pos,
                {
                    "life": life,
                    "name": project,
                },
            )
        )

    virus_id_idx = {}
    for _ in range(m):
        virus_id, pos = map(int, input().split())
        virus_line.append(
            (
                pos,
                {"id": virus_id, "active": True, "target_projects": {}},
            )
        )
        virus_id_idx[virus_id] = len(virus_line) - 1

    for _ in range(q):
        virus_id, project, dmg = input().split()
        virus_id, dmg = int(virus_id), int(dmg)

        virus_line[virus_id_idx[virus_id]][1]["target_projects"][project] = dmg

    survivor = solve(project_line, virus_line)
    print(len(survivor))
    print(" ".join(survivor))


if __name__ == "__main__":
    main()
