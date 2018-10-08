import React from "react";
import Layout from "../components/layout";

import "./common.css";
import "./index.css";
import titleImg from "../images/title.png";
import crossWaterMp4 from "../images/crossWater.mp4";
import goIntoDungeonMp4 from "../images/goIntoDungeon.mp4";
import inGameMenuImg from "../images/inGameMenu.png";
import attackBlobImg from "../images/attackBlob.png";

const IndexPage = () => (
    <Layout className="home">
        <img className="titleImage" src={titleImg} alt="Ardynia Title Screen" />
        <p>
            Explore dungeons, solve puzzles, fight bosses, all from your pocket.
            Ardynia is an adventure game for the Arduboy.
        </p>
        <a className="downloadHere">Download Here</a>

        <div className="mediaContainer">
            <video
                className="crossWater"
                src={crossWaterMp4}
                muted
                width="256"
                height="128"
                autoPlay
                loop
                playsinline
                controls
            />
            <div className="divider" />
            <video
                className="goIntoDungeon"
                src={goIntoDungeonMp4}
                muted
                width="256"
                height="128"
                autoPlay
                loop
                playsinline
                controls
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
