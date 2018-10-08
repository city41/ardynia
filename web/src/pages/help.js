import React from "react";
import Layout from "../components/layout";
import Hint from "../components/hint";

import "./common.css";
import "./help.css";
import titleImg from "../images/title.png";
import dpadImg from "../images/dpad.png";
import aButtonImg from "../images/aButton.png";
import bButtonImg from "../images/bButton.png";

const HelpPage = () => (
    <Layout className="help">
        <img className="titleImage" src={titleImg} alt="Ardynia Title Screen" />
        <p>Explore the land and beat the three demons</p>
        <h2>Controls</h2>
        <div className="controlsContainer">
            <div>
                <img src={dpadImg} alt="directional pad" />
            </div>
            <div>move around</div>
            <div>
                press <img src={aButtonImg} alt="the a button" />
            </div>
            <div>attack with your main weapon</div>
            <div>
                hold <img src={aButtonImg} alt="the a button" />
            </div>
            <div>Go into the inventory menu</div>
            <div>
                press <img src={bButtonImg} alt="the b button" />
            </div>
            <div>use your equipped item</div>
        </div>
        <h2>Hints</h2>
        <Hint>
            There are six heart containers to find, for a total of a 8 heart
            life meter
        </Hint>
        <Hint>
            There is always enough keys. If you can't get past a lock, keep
            trying different things
        </Hint>
        <Hint>
            The bosses might be immune to your sword, maybe try something else?
        </Hint>
    </Layout>
);

export default HelpPage;
