import React from "react";
import Layout from "../components/layout";

import "./updates.css";

const UpdatesPage = () => (
    <Layout className="updates">
        <section>
            <h2>Sept 30th, 2018</h2>
            <p>
                The game is almost done! I am just testing, and tweaking really
                minor things. It will be released early October. I am very happy
                with how it turned out! I think it's pretty fun.
            </p>
        </section>
        <section>
            <h2>Sept 23th, 2018</h2>
            <h3>Completed</h3>
            <ul>
                <li>All dungeons, overworld and secrets are complete</li>
            </ul>
            <h3>Still To Do</h3>
            <ul>
                <li>polish and polish some more</li>
                <li>fix bugs</li>
                <li>better sound</li>
            </ul>
            <h3>Expected launch date</h3>
            <p>
                Starting to feel like late October is doable. It's going
                smoother than I thought it would.
            </p>
        </section>
        <section>
            <h2>Sept 16th, 2018</h2>
            <h3>Completed</h3>
            <ul>
                <li>first dungeon completed</li>
            </ul>
            <h3>Still To Do</h3>
            <ul>
                <li>second and third dungeon</li>
                <li>fix bugs</li>
                <li>polish a lot of stuff</li>
                <li>better sound</li>
            </ul>
            <h3>Expected launch date</h3>
            <p>
                Still a bit early to tell, but I'll put out a conservative date
                of early November 2018. I think I'll finish it before that
                though.
            </p>
        </section>
        <section>
            <h2>Sept 10th, 2018</h2>
            <ul>
                <li>
                    <a href="http://www.mattgreer.org/articles/squeezing-the-arduboy-for-every-byte/">
                        blog post
                    </a>{" "}
                    about the game's development. In particular, techniques on
                    how I saved flash storage to fit more content into the game
                </li>
            </ul>
        </section>
        <section>
            <h2>Sept 9th, 2018</h2>
            <h3>Completed</h3>
            <ul>
                <li>just launched this website</li>
                <li>engine is completely done</li>
                <li>all enemies, equipment and bosses are implemented</li>
                <li>overworld map is mostly done</li>
            </ul>
            <h3>Still To Do</h3>
            <ul>
                <li>
                    dungeons are spec'd out, but still much work to do here.
                    Planning out puzzles and flow.
                </li>
                <li>
                    Expecting to still need a good amount of time to fix bugs
                    and really polish the details nicely.
                </li>
                <li>
                    Will likely end up implementing new items, enemies, etc as
                    get further into dungeon design.
                </li>
            </ul>
            <h3>Expected launch date</h3>
            <p>No idea at this point</p>
        </section>
    </Layout>
);

export default UpdatesPage;
