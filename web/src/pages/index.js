import React from "react";
import Layout from "../components/layout";

import "./common.css";
import "./index.css";
import titleImg from "../images/title.png";
import crossWaterGif from "../images/crossWater.gif";
import goIntoDungeonGif from "../images/goIntoDungeon.gif";
import inGameMenuImg from "../images/inGameMenu.png";
import attackBlobImg from "../images/attackBlob.png";

const IndexPage = () => (
    <Layout className="home">
        <img className="titleImage" src={titleImg} alt="Ardynia Title Screen" />
        <p>
            Explore dungeons, solve puzzles, fight bosses, all from your pocket.
            Ardynia is an adventure game for the Arduboy.
        </p>
        <a
            href="https://github.com/city41/ardynia/releases/tag/1.1.0"
            className="downloadHere"
        >
            Download Here
        </a>

        <div className="mediaContainer">
            <img
                className="crossWater gif"
                src={crossWaterGif}
                alt="crossing a river"
            />
            <div className="divider" />
            <img
                className="goIntoDungeon gif"
                src={goIntoDungeonGif}
                alt="going into a dungeon"
            />
            <img
                className="inGameMenu"
                src={inGameMenuImg}
                alt="in game menu"
            />
            <img
                className="attackBlob"
                src={attackBlobImg}
                alt="in game menu"
            />
        </div>
        <p>&copy;2018 Matt Greer</p>
    </Layout>
);

export default IndexPage;
